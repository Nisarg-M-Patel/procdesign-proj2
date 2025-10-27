// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline__Syms.h"
#include "Vpipeline_pipeline.h"

void Vpipeline_pipeline___ctor_var_reset(Vpipeline_pipeline* vlSelf);

Vpipeline_pipeline::Vpipeline_pipeline(Vpipeline__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpipeline_pipeline___ctor_var_reset(this);
}

void Vpipeline_pipeline::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpipeline_pipeline::~Vpipeline_pipeline() {
}
