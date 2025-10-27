// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpipeline.h for the primary calling header

#ifndef VERILATED_VPIPELINE___024ROOT_H_
#define VERILATED_VPIPELINE___024ROOT_H_  // guard

#include "verilated.h"
class Vpipeline_pipeline;


class Vpipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpipeline___024root final : public VerilatedModule {
  public:
    // CELLS
    Vpipeline_pipeline* pipeline;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpipeline___024root(Vpipeline__Syms* symsp, const char* v__name);
    ~Vpipeline___024root();
    VL_UNCOPYABLE(Vpipeline___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
