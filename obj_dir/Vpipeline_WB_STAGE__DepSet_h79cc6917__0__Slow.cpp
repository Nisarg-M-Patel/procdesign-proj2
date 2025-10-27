// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline_WB_STAGE.h"

VL_ATTR_COLD void Vpipeline_WB_STAGE___ctor_var_reset(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reset = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(141, vlSelf->__PVT__from_MEM_latch);
    vlSelf->__PVT__from_WB_to_FE = VL_RAND_RESET_I(1);
    vlSelf->__PVT__from_WB_to_DE = VL_RAND_RESET_Q(38);
    vlSelf->__PVT__from_WB_to_AGEX = VL_RAND_RESET_I(1);
    vlSelf->__PVT__from_WB_to_MEM = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rd_val_WB = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(1024, vlSelf->last_WB_value);
    VL_RAND_RESET_W(256, vlSelf->WB_counters);
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
}
