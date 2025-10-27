// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline_WB_STAGE.h"
#include "Vpipeline__Syms.h"

void Vpipeline_WB_STAGE___ctor_var_reset(Vpipeline_WB_STAGE* vlSelf);

Vpipeline_WB_STAGE::Vpipeline_WB_STAGE(Vpipeline__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpipeline_WB_STAGE___ctor_var_reset(this);
}

void Vpipeline_WB_STAGE::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpipeline_WB_STAGE::~Vpipeline_WB_STAGE() {
}
