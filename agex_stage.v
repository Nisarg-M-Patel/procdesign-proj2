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
  assign AGEX_latch_out = AGEX_latch;
  
  wire[`AGEX_latch_WIDTH-1:0] AGEX_latch_contents; 
  
  wire valid_AGEX; 
  wire [`INSTBITS-1:0]inst_AGEX; 
  wire [`DBITS-1:0]PC_AGEX;
  wire [`DBITS-1:0] inst_count_AGEX; 
  wire [`DBITS-1:0] pcplus_AGEX; 
  wire [`IOPBITS-1:0] op_I_AGEX;
  reg br_cond_AGEX;
 
  /////////////////////////////////////////////////////////////////////////////

  wire is_br_AGEX;
  wire is_jmp_AGEX;
  wire wr_reg_AGEX;
  wire [`REGNOBITS-1:0] wregno_AGEX;

  wire [`DBITS-1:0] regval1_AGEX;
  wire [`DBITS-1:0] regval2_AGEX;
  wire [`DBITS-1:0] sxt_imm_AGEX;

  reg [`DBITS-1:0] br_target_AGEX;
  wire br_mispred_AGEX;
  wire jmp_mispred_AGEX;
  reg [`DBITS-1:0] aluout_AGEX;
  
  always @ (*) begin
    case (op_I_AGEX)
      `BEQ_I : br_cond_AGEX = (regval1_AGEX == regval2_AGEX);
      `BNE_I : br_cond_AGEX = (regval1_AGEX != regval2_AGEX);
      `BLT_I : br_cond_AGEX = ($signed(regval1_AGEX) < $signed(regval2_AGEX));
      `BGE_I : br_cond_AGEX = ($signed(regval1_AGEX) >= $signed(regval2_AGEX));
      `BLTU_I: br_cond_AGEX = (regval1_AGEX < regval2_AGEX);
      `BGEU_I : br_cond_AGEX = (regval1_AGEX >= regval2_AGEX);
      default : br_cond_AGEX = 1'b0;
    endcase
  end

  always @ (*) begin
  case (op_I_AGEX)
    `ADD_I  : aluout_AGEX = regval1_AGEX + regval2_AGEX;
    `SUB_I  : aluout_AGEX = regval1_AGEX - regval2_AGEX;
    `AND_I  : aluout_AGEX = regval1_AGEX & regval2_AGEX;
    `OR_I   : aluout_AGEX = regval1_AGEX | regval2_AGEX;
    `XOR_I  : aluout_AGEX = regval1_AGEX ^ regval2_AGEX;
    `SLT_I  : aluout_AGEX = ($signed(regval1_AGEX) < $signed(regval2_AGEX)) ? 1 : 0;
    `SLTU_I : aluout_AGEX = (regval1_AGEX < regval2_AGEX) ? 1 : 0;
    `SRA_I  : aluout_AGEX = $signed(regval1_AGEX) >>> regval2_AGEX[4:0];
    `SRL_I  : aluout_AGEX = regval1_AGEX >> regval2_AGEX[4:0];
    `SLL_I  : aluout_AGEX = regval1_AGEX << regval2_AGEX[4:0];
    `MUL_I  : aluout_AGEX = regval1_AGEX * regval2_AGEX;
    `ADDI_I : aluout_AGEX = regval1_AGEX + sxt_imm_AGEX;
    `ANDI_I : aluout_AGEX = regval1_AGEX & sxt_imm_AGEX;
    `ORI_I  : aluout_AGEX = regval1_AGEX | sxt_imm_AGEX;
    `XORI_I : aluout_AGEX = regval1_AGEX ^ sxt_imm_AGEX;
    `SLTI_I : aluout_AGEX = ($signed(regval1_AGEX) < $signed(sxt_imm_AGEX)) ? 1 : 0;
    `SLTIU_I: aluout_AGEX = (regval1_AGEX < sxt_imm_AGEX) ? 1 : 0;
    `SRAI_I : aluout_AGEX = $signed(regval1_AGEX) >>> sxt_imm_AGEX[4:0];
    `SRLI_I : aluout_AGEX = regval1_AGEX >> sxt_imm_AGEX[4:0];
    `SLLI_I : aluout_AGEX = regval1_AGEX << sxt_imm_AGEX[4:0];
    `LUI_I  : aluout_AGEX = sxt_imm_AGEX;
    `AUIPC_I: aluout_AGEX = PC_AGEX + sxt_imm_AGEX;
    `JAL_I  : aluout_AGEX = pcplus_AGEX;
    `JALR_I : aluout_AGEX = pcplus_AGEX;
    `LW_I   : aluout_AGEX = regval1_AGEX + sxt_imm_AGEX;
    `SW_I   : aluout_AGEX = regval1_AGEX + sxt_imm_AGEX;
    default : aluout_AGEX = '0;
  endcase
  end

  always @(*)begin
    if (is_br_AGEX && br_cond_AGEX) begin
      br_target_AGEX = PC_AGEX + sxt_imm_AGEX;
    end else if (op_I_AGEX == `JAL_I) begin
      br_target_AGEX = PC_AGEX + sxt_imm_AGEX;
    end else if (op_I_AGEX == `JALR_I) begin
      br_target_AGEX = (regval1_AGEX + sxt_imm_AGEX) & ~32'b1;
    end else begin
      br_target_AGEX = pcplus_AGEX;
    end
  end

  assign br_mispred_AGEX = (is_br_AGEX && br_cond_AGEX
                         && (br_target_AGEX != pcplus_AGEX)) ? 1 : 0;
                         
  assign jmp_mispred_AGEX = is_jmp_AGEX ? 1 : 0;

    assign  {                     
                                  valid_AGEX,
                                  inst_AGEX,
                                  PC_AGEX,
                                  pcplus_AGEX,
                                  op_I_AGEX,
                                  inst_count_AGEX,
                                  regval1_AGEX,
                                  regval2_AGEX,
                                  sxt_imm_AGEX,
                                  is_br_AGEX,
                                  is_jmp_AGEX,
                                  wr_reg_AGEX,
                                  wregno_AGEX
                                  } = from_DE_latch; 
    
 
  assign AGEX_latch_contents = {
                                valid_AGEX,
                                inst_AGEX,
                                PC_AGEX,
                                op_I_AGEX,
                                inst_count_AGEX,
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


  assign from_AGEX_to_FE = { 
      br_mispred_AGEX || jmp_mispred_AGEX,
      br_target_AGEX
  };

  assign from_AGEX_to_DE = { 
    br_mispred_AGEX || jmp_mispred_AGEX
  };

endmodule