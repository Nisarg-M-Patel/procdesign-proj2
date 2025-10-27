// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline_WB_STAGE.h"
#include "Vpipeline__Syms.h"

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->WB_counters[0U] = 0U;
        vlSelf->WB_counters[1U] = 0U;
        vlSelf->WB_counters[2U] = 0U;
        vlSelf->WB_counters[3U] = 0U;
        vlSelf->WB_counters[4U] = 0U;
        vlSelf->WB_counters[5U] = 0U;
        vlSelf->WB_counters[6U] = 0U;
        vlSelf->WB_counters[7U] = 0U;
    } else {
        vlSelf->WB_counters[0U] = (1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                         >> 0xcU));
        vlSelf->WB_counters[1U] = ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                    << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                 >> 0xcU));
        vlSelf->WB_counters[2U] = (IData)((((QData)((IData)(
                                                            (0x3fU 
                                                             & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                                >> 6U)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                                               << 0x14U) 
                                                              | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                                                 >> 0xcU))))));
        vlSelf->WB_counters[3U] = (IData)(((((QData)((IData)(
                                                             (0x3fU 
                                                              & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                                 >> 6U)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                                                << 0x14U) 
                                                               | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                                                  >> 0xcU))))) 
                                           >> 0x20U));
        vlSelf->WB_counters[4U] = (1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                         >> 5U));
        vlSelf->WB_counters[5U] = (IData)((((QData)((IData)(
                                                            ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                              << 0x1aU) 
                                                             | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                >> 6U)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             (0x1fU 
                                                              & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])))));
        vlSelf->WB_counters[6U] = (IData)(((((QData)((IData)(
                                                             ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                               << 0x1aU) 
                                                              | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                 >> 6U)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (0x1fU 
                                                               & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])))) 
                                           >> 0x20U));
        vlSelf->WB_counters[7U] = 0U;
    }
}

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1\n"); );
    // Body
    vlSelf->__PVT__from_WB_to_DE = (((QData)((IData)(
                                                     (0x3fU 
                                                      & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U]))) 
                                     << 0x20U) | (QData)((IData)(
                                                                 ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                                   << 0x1aU) 
                                                                  | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                     >> 6U)))));
}

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__unnamedblk1__DOT__i = 0x20U;
        vlSelf->last_WB_value[0U] = 0U;
        vlSelf->last_WB_value[1U] = 0U;
        vlSelf->last_WB_value[2U] = 0U;
        vlSelf->last_WB_value[3U] = 0U;
        vlSelf->last_WB_value[4U] = 0U;
        vlSelf->last_WB_value[5U] = 0U;
        vlSelf->last_WB_value[6U] = 0U;
        vlSelf->last_WB_value[7U] = 0U;
        vlSelf->last_WB_value[8U] = 0U;
        vlSelf->last_WB_value[9U] = 0U;
        vlSelf->last_WB_value[0xaU] = 0U;
        vlSelf->last_WB_value[0xbU] = 0U;
        vlSelf->last_WB_value[0xcU] = 0U;
        vlSelf->last_WB_value[0xdU] = 0U;
        vlSelf->last_WB_value[0xeU] = 0U;
        vlSelf->last_WB_value[0xfU] = 0U;
        vlSelf->last_WB_value[0x10U] = 0U;
        vlSelf->last_WB_value[0x11U] = 0U;
        vlSelf->last_WB_value[0x12U] = 0U;
        vlSelf->last_WB_value[0x13U] = 0U;
        vlSelf->last_WB_value[0x14U] = 0U;
        vlSelf->last_WB_value[0x15U] = 0U;
        vlSelf->last_WB_value[0x16U] = 0U;
        vlSelf->last_WB_value[0x17U] = 0U;
        vlSelf->last_WB_value[0x18U] = 0U;
        vlSelf->last_WB_value[0x19U] = 0U;
        vlSelf->last_WB_value[0x1aU] = 0U;
        vlSelf->last_WB_value[0x1bU] = 0U;
        vlSelf->last_WB_value[0x1cU] = 0U;
        vlSelf->last_WB_value[0x1dU] = 0U;
        vlSelf->last_WB_value[0x1eU] = 0U;
        vlSelf->last_WB_value[0x1fU] = 0U;
    } else if ((0x20U & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])) {
        VL_ASSIGNSEL_WI(1024,32,(0x3e0U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                           << 5U)), vlSelf->last_WB_value, 
                        ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                          << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                       >> 6U)));
    }
}
