`include "define.vh" 

module AGEX_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_MEM_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX,    
  input wire [`from_WB_to_AGEX_WIDTH-1:0] from_WB_to_AGEX,   
  input wire [`DE_latch_WIDTH-1:0] from_DE_latch,
  output wire [`AGEX_latch_WIDTH-1:0] AGEX_latch_out,
  output wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,
  output wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE
);

  `UNUSED_VAR (from_MEM_to_AGEX)
  `UNUSED_VAR (from_WB_to_AGEX)

  reg [`AGEX_latch_WIDTH-1:0] AGEX_latch; 
  // wire to send the AGEX latch contents to other pipeline stages 
  assign AGEX_latch_out = AGEX_latch;
  
  wire[`AGEX_latch_WIDTH-1:0] AGEX_latch_contents; 
  
  wire valid_AGEX; 
  wire [`INSTBITS-1:0]inst_AGEX; 
  wire [`DBITS-1:0]PC_AGEX;
  wire [`DBITS-1:0] inst_count_AGEX; 
  wire [`DBITS-1:0] pcplus_AGEX; 
  wire [`IOPBITS-1:0] op_I_AGEX;
  reg br_cond_AGEX; // 1 means a branch condition is satisified. 0 means a branch condition is not satisifed
 
  /////////////////////////////////////////////////////////////////////////////

  wire is_br_AGEX;
  wire wr_reg_AGEX;
  wire [`REGNOBITS-1:0] wregno_AGEX;

  wire [`DBITS-1:0] regval1_AGEX;
  wire [`DBITS-1:0] regval2_AGEX;
  wire [`DBITS-1:0] sxt_imm_AGEX;

  reg [`DBITS-1:0] br_target_AGEX;
  wire br_mispred_AGEX;
  reg [`DBITS-1:0] aluout_AGEX;
  
  // Calculate branch condition
  // TODO: complete the code
  always @ (*) begin
    case (op_I_AGEX)
      `BEQ_I : br_cond_AGEX = (regval1_AGEX == regval2_AGEX); // write correct code to check the branch condition. 
      /*
      `BNE_I : ...
      `BLT_I : ...
      `BGE_I : ...
      `BLTU_I: ..
      `BGEU_I : ...
      */
      default : br_cond_AGEX = 1'b0;
    endcase
  end

  // Compute ALU operations  (alu out or memory addresses)
  // TODO: complete the code
  always @ (*) begin
  case (op_I_AGEX)
    `ADD_I  : aluout_AGEX = regval1_AGEX + regval2_AGEX;
    `ADDI_I : aluout_AGEX = regval1_AGEX + sxt_imm_AGEX;
    default : aluout_AGEX = '0;
  endcase
  end

  // branch target needs to be computed here 
  // computed branch target needs to send to other pipeline stages (br_target_AGEX)
  // TODO: complete the code
  always @(*)begin
    if (is_br_AGEX && br_cond_AGEX)
      br_target_AGEX = PC_AGEX + sxt_imm_AGEX;
    else
      br_target_AGEX = pcplus_AGEX;
  end

  assign br_mispred_AGEX = (is_br_AGEX && br_cond_AGEX
                         && (br_target_AGEX != pcplus_AGEX)) ? 1 : 0;

    assign  {                     
                                  valid_AGEX,
                                  inst_AGEX,
                                  PC_AGEX,
                                  pcplus_AGEX,
                                  op_I_AGEX,
                                  inst_count_AGEX,
                                          //  TODO: more signals might needed
                                  regval1_AGEX,
                                  regval2_AGEX,
                                  sxt_imm_AGEX,
                                  is_br_AGEX,
                                  wr_reg_AGEX,
                                  wregno_AGEX
                                  } = from_DE_latch; 
    
 
  assign AGEX_latch_contents = {
                                valid_AGEX,
                                inst_AGEX,
                                PC_AGEX,
                                op_I_AGEX,
                                inst_count_AGEX,
                                       // TODO: more signals might needed
                                aluout_AGEX,
                                wr_reg_AGEX,
                                wregno_AGEX
                                 }; 
 
  always @ (posedge clk ) begin
    if(reset) begin
      AGEX_latch <= {`AGEX_latch_WIDTH{1'b0}};
        end 
    else 
        begin
            AGEX_latch <= AGEX_latch_contents ;
        end 
  end


  // forward signals to FE stage
  assign from_AGEX_to_FE = { 
      //  TODO: more signals might needed
      br_mispred_AGEX,
      br_target_AGEX
  };

  // forward signals to DE stage
  assign from_AGEX_to_DE = { 
    //  TODO: more signals might needed
    br_mispred_AGEX
  };

endmodule
