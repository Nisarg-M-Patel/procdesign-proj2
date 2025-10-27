// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpipeline.h for the primary calling header

#ifndef VERILATED_VPIPELINE_PIPELINE_H_
#define VERILATED_VPIPELINE_PIPELINE_H_  // guard

#include "verilated.h"
class Vpipeline_WB_STAGE;


class Vpipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpipeline_pipeline final : public VerilatedModule {
  public:
    // CELLS
    Vpipeline_WB_STAGE* my_WB_stage;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __PVT__from_DE_to_FE;
    CData/*0:0*/ __PVT__from_AGEX_to_DE;
    CData/*0:0*/ __PVT__my_FE_stage__DOT__valid_FE;
    CData/*2:0*/ my_DE_stage__DOT____Vxrand_h9c26cae2__0;
    CData/*3:0*/ my_DE_stage__DOT____Vxrand_h9c270190__0;
    CData/*5:0*/ __PVT__my_DE_stage__DOT__op_I_DE;
    CData/*3:0*/ __PVT__my_DE_stage__DOT__type_I_DE;
    CData/*2:0*/ __PVT__my_DE_stage__DOT__type_immediate_DE;
    CData/*0:0*/ __PVT__my_DE_stage__DOT__wr_reg_DE;
    CData/*0:0*/ __PVT__my_DE_stage__DOT__use_rs1_DE;
    CData/*0:0*/ __PVT__my_DE_stage__DOT__use_rs2_DE;
    CData/*0:0*/ __PVT__my_MEM_stage__DOT__wr_mem_MEM;
    IData/*31:0*/ __PVT__cycle_count;
    VlWide<5>/*128:0*/ __PVT__my_FE_stage__DOT__FE_latch;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__PC_FE_latch;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__inst_count_FE;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__inst_count_AGEX;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__pcplus_FE;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__br_target_AGEX;
    VlWide<8>/*237:0*/ __PVT__my_DE_stage__DOT__DE_latch;
    IData/*31:0*/ __PVT__my_DE_stage__DOT__in_use_regs;
    VlWide<5>/*140:0*/ __PVT__my_AGEX_stage__DOT__AGEX_latch;
    VlWide<5>/*140:0*/ __PVT__my_MEM_stage__DOT__MEM_latch;
    IData/*31:0*/ __PVT__my_MEM_stage__DOT__memaddr_MEM;
    IData/*31:0*/ __PVT__my_MEM_stage__DOT__wr_val_MEM;
    VlWide<5>/*128:0*/ __Vdly__my_FE_stage__DOT__FE_latch;
    VlUnpacked<IData/*31:0*/, 16384> __PVT__my_FE_stage__DOT__imem;
    VlUnpacked<IData/*31:0*/, 32> __PVT__my_DE_stage__DOT__regs;
    VlUnpacked<IData/*31:0*/, 16384> __PVT__my_MEM_stage__DOT__dmem;

    // INTERNAL VARIABLES
    Vpipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpipeline_pipeline(Vpipeline__Syms* symsp, const char* v__name);
    ~Vpipeline_pipeline();
    VL_UNCOPYABLE(Vpipeline_pipeline);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
