`include "define.vh" 

module FE_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE,
  input wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,   
  input wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE,   
  input wire [`from_WB_to_FE_WIDTH-1:0] from_WB_to_FE, 
  output wire [`FE_latch_WIDTH-1:0] FE_latch_out,
  output wire [`BHR_WIDTH-1:0] current_bhr_to_AGEX  // Added: pass current BHR to AGEX
);

  `UNUSED_VAR (from_MEM_to_FE)
  `UNUSED_VAR (from_WB_to_FE)

  // I-MEM
  (* ram_init_file = `IDMEMINITFILE *)
  reg [`DBITS-1:0] imem [`IMEMWORDS-1:0];
 
  initial begin
    $readmemh(`IDMEMINITFILE , imem);
  end

  /* pipeline latch */ 
  reg [`FE_latch_WIDTH-1:0] FE_latch;  // FE latch 
  wire valid_FE;
   
  assign valid_FE = 1'b1;
  reg [`DBITS-1:0] PC_FE_latch; // PC latch in the FE stage   
  
  reg [`DBITS-1:0] inst_count_FE; /* for debugging purpose */ 
  
  wire [`DBITS-1:0] inst_count_AGEX; /* for debugging purpose. resent the instruction counter */ 

  wire [`INSTBITS-1:0] inst_FE;  // instruction value in the FE stage 
  wire [`DBITS-1:0] pcplus_FE;  // pc plus value in the FE stage 
  wire stall_pipe_FE; // signal to indicate when a front-end needs to be stall
  
  wire [`FE_latch_WIDTH-1:0] FE_latch_contents;  // the signals that will be FE latch contents 
  
  // Branch prediction structures
  reg [`BHR_WIDTH-1:0] BHR_FE;  // Branch History Register
  reg [`PHT_COUNTER_BITS-1:0] PHT [`PHT_ENTRIES-1:0];  // Pattern History Table
  reg [`DBITS-1:0] BTB [`BTB_ENTRIES-1:0];  // Branch Target Buffer
  
  // *** ADDED: Branch prediction accuracy counters ***
  reg [`DBITS-1:0] total_branches_FE /* verilator public */;         // Total executed branch instructions
  reg [`DBITS-1:0] mispredicted_branches_FE /* verilator public */;  // Total mispredicted branches
  // Branch prediction signals
  wire [`PHT_INDEX_BITS-1:0] pht_index_FE;
  wire [3:0] btb_index_FE;
  wire [`PHT_COUNTER_BITS-1:0] pht_counter_FE;
  wire pred_taken_FE;
  wire [`DBITS-1:0] pred_target_FE;
  wire btb_hit_FE;
  wire [`DBITS-1:0] next_pc_FE;
  
  // Compute PHT index: PC[9:2] XOR BHR
  assign pht_index_FE = PC_FE_latch[9:2] ^ BHR_FE;
  
  // Compute BTB index: PC[5:2]  
  assign btb_index_FE = PC_FE_latch[5:2];
  
  // Read from PHT and BTB
  assign pht_counter_FE = PHT[pht_index_FE];
  assign pred_taken_FE = pht_counter_FE[1];  // MSB determines taken/not taken
  assign pred_target_FE = BTB[btb_index_FE];
  
  // For simplicity, assume BTB always hits (in real implementation, you'd have valid bits)
  assign btb_hit_FE = 1'b1;
  
  // Compute next PC based on branch prediction
  assign next_pc_FE = (btb_hit_FE && pred_taken_FE) ? pred_target_FE : pcplus_FE;
  
  // reading instruction from imem 
  assign inst_FE = imem[PC_FE_latch[`IMEMADDRBITS-1:`IMEMWORDBITS]];  // this code works. imem is stored 4B together 
  
  // wire to send the FE latch contents to the DE stage 
  assign FE_latch_out = FE_latch; 
 
  // This is the value of "incremented PC", computed in the FE stage
  assign pcplus_FE = PC_FE_latch + `INSTSIZE;
  
  // the order of latch contents should be matched in the decode stage when we extract the contents. 
  assign FE_latch_contents = {
                              valid_FE, 
                              inst_FE, 
                              PC_FE_latch, 
                              pcplus_FE, // please feel free to add more signals such as valid bits etc. 
                              inst_count_FE,
                              pht_index_FE  // Pass this to DE stage for later update
                              // if you add more bits here, please increase the width of latch in VX_define.vh 
                              };

  // Signals from other stages
  wire br_mispred_AGEX;  
  wire [`DBITS-1:0] br_target_AGEX;
  wire update_bhr_AGEX;
  wire [`BHR_WIDTH-1:0] new_bhr_AGEX;
  wire [`PHT_INDEX_BITS-1:0] pht_index_AGEX;  // Added: PHT index from AGEX for updates
  wire is_branch_executing_AGEX;              // *** ADDED: branch execution signal ***

  assign {
    stall_pipe_FE
  } = from_DE_to_FE[0]; 

  // *** UPDATED: signal extraction to include branch execution signal ***
  assign {
    br_mispred_AGEX,
    br_target_AGEX,
    update_bhr_AGEX,
    new_bhr_AGEX,
    pht_index_AGEX,
    is_branch_executing_AGEX  // *** ADDED: extract branch execution signal ***
  } = from_AGEX_to_FE;

  // Added: Pass current BHR to AGEX stage
  assign current_bhr_to_AGEX = BHR_FE;

  // *** ADDED: Branch prediction accuracy counting logic ***
  always @(posedge clk) begin
    if (reset) begin
      total_branches_FE <= 0;
      mispredicted_branches_FE <= 0;
    end else begin
      // Count total branches executed
      if (is_branch_executing_AGEX) begin
        total_branches_FE <= total_branches_FE + 1;
      end
      
      // Count mispredicted branches
      if (is_branch_executing_AGEX && br_mispred_AGEX) begin
        mispredicted_branches_FE <= mispredicted_branches_FE + 1;
      end
    end
  end

  // Initialize PHT and BTB
  integer i;
  initial begin
    for (i = 0; i < `PHT_ENTRIES; i = i + 1) begin
      PHT[i] = 2'b01;  // Initialize to 1 (weakly not taken)
    end
    for (i = 0; i < `BTB_ENTRIES; i = i + 1) begin
      BTB[i] = `STARTPC;  // Initialize BTB entries
    end
    BHR_FE = {`BHR_WIDTH{1'b0}};  // Initialize BHR to 0
  end

  always @ (posedge clk) begin
    /* you need to extend this always block */
    if (reset) begin 
      PC_FE_latch <= `STARTPC;
      inst_count_FE <= 1;  /* inst_count starts from 1 for easy human reading. 1st fetch instructions can have 1 */ 
      BHR_FE <= {`BHR_WIDTH{1'b0}};
    end 
    else if (br_mispred_AGEX) begin
      PC_FE_latch <= br_target_AGEX;
      if (update_bhr_AGEX)
        BHR_FE <= new_bhr_AGEX;
    end
    else if (stall_pipe_FE) begin
      PC_FE_latch <= PC_FE_latch; 
      if (update_bhr_AGEX)
        BHR_FE <= new_bhr_AGEX;
    end
    else begin 
      PC_FE_latch <= next_pc_FE;  // Use predicted PC instead of pcplus_FE
      inst_count_FE <= inst_count_FE + 1; 
      if (update_bhr_AGEX)
        BHR_FE <= new_bhr_AGEX;
    end 
  end
  
  // Fixed: Update PHT and BTB from AGEX stage using correct indices
  always @(posedge clk) begin
    if (reset) begin
      // Already initialized above
    end else begin
      // Update PHT when we get branch resolution from AGEX
      if (update_bhr_AGEX) begin
        // Fixed: Use PHT index from AGEX stage, not FE stage
        case (PHT[pht_index_AGEX])
          2'b00: PHT[pht_index_AGEX] <= new_bhr_AGEX[0] ? 2'b01 : 2'b00;  // strongly not taken
          2'b01: PHT[pht_index_AGEX] <= new_bhr_AGEX[0] ? 2'b10 : 2'b00;  // weakly not taken
          2'b10: PHT[pht_index_AGEX] <= new_bhr_AGEX[0] ? 2'b11 : 2'b01;  // weakly taken
          2'b11: PHT[pht_index_AGEX] <= new_bhr_AGEX[0] ? 2'b11 : 2'b10;  // strongly taken
        endcase
        
        // Fixed: Update BTB with branch target using PC from AGEX stage
        // Use the PC of the instruction in AGEX that's being resolved
        BTB[br_target_AGEX[5:2]] <= br_target_AGEX;  // Use target PC to compute BTB index
      end
    end
  end

  always @ (posedge clk) begin
    if (reset) begin 
      FE_latch <= '0; 
    end else begin 
      if (br_mispred_AGEX)
        FE_latch <= '0;
      else if (stall_pipe_FE)
        FE_latch <= FE_latch; 
      else 
        FE_latch <= FE_latch_contents; 
    end  
  end

endmodule