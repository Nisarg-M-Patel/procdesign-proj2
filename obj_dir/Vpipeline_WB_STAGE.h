// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpipeline.h for the primary calling header

#ifndef VERILATED_VPIPELINE_WB_STAGE_H_
#define VERILATED_VPIPELINE_WB_STAGE_H_  // guard

#include "verilated.h"


class Vpipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpipeline_WB_STAGE final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__reset,0,0);
    VL_OUT8(__PVT__from_WB_to_FE,0,0);
    VL_OUT8(__PVT__from_WB_to_AGEX,0,0);
    VL_OUT8(__PVT__from_WB_to_MEM,0,0);
    VL_INW(__PVT__from_MEM_latch,140,0,5);
    IData/*31:0*/ __PVT__rd_val_WB;
    VlWide<32>/*1023:0*/ last_WB_value;
    VlWide<8>/*255:0*/ WB_counters;
    IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
    VL_OUT64(__PVT__from_WB_to_DE,37,0);

    // INTERNAL VARIABLES
    Vpipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpipeline_WB_STAGE(Vpipeline__Syms* symsp, const char* v__name);
    ~Vpipeline_WB_STAGE();
    VL_UNCOPYABLE(Vpipeline_WB_STAGE);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
