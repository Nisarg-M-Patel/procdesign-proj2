// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline__Syms.h"
#include "Vpipeline___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpipeline___024root___dump_triggers__act(Vpipeline___024root* vlSelf);
#endif  // VL_DEBUG

void Vpipeline___024root___eval_triggers__act(Vpipeline___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(1U, ((~ (IData)(vlSelf->clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0)));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpipeline___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vpipeline_pipeline___nba_sequent__TOP__pipeline__0(Vpipeline_pipeline* vlSelf);
void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0(Vpipeline_WB_STAGE* vlSelf);
void Vpipeline_pipeline___nba_sequent__TOP__pipeline__1(Vpipeline_pipeline* vlSelf);
void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1(Vpipeline_WB_STAGE* vlSelf);
void Vpipeline_pipeline___nba_sequent__TOP__pipeline__2(Vpipeline_pipeline* vlSelf);
void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2(Vpipeline_WB_STAGE* vlSelf);

void Vpipeline___024root___eval_nba(Vpipeline___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vpipeline_pipeline___nba_sequent__TOP__pipeline__0((&vlSymsp->TOP__pipeline));
        vlSelf->__Vm_traceActivity[1U] = 1U;
        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0((&vlSymsp->TOP__pipeline__my_WB_stage));
        Vpipeline_pipeline___nba_sequent__TOP__pipeline__1((&vlSymsp->TOP__pipeline));
        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1((&vlSymsp->TOP__pipeline__my_WB_stage));
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vpipeline_pipeline___nba_sequent__TOP__pipeline__2((&vlSymsp->TOP__pipeline));
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2((&vlSymsp->TOP__pipeline__my_WB_stage));
    }
}
