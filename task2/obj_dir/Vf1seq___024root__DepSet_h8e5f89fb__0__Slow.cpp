// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1seq.h for the primary calling header

#include "verilated.h"

#include "Vf1seq___024root.h"

VL_ATTR_COLD void Vf1seq___024root___settle__TOP__0(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___settle__TOP__0\n"); );
    // Body
    if (((((((((0U == vlSelf->f1seq__DOT__currentstate) 
               | (1U == vlSelf->f1seq__DOT__currentstate)) 
              | (2U == vlSelf->f1seq__DOT__currentstate)) 
             | (3U == vlSelf->f1seq__DOT__currentstate)) 
            | (4U == vlSelf->f1seq__DOT__currentstate)) 
           | (5U == vlSelf->f1seq__DOT__currentstate)) 
          | (6U == vlSelf->f1seq__DOT__currentstate)) 
         | (7U == vlSelf->f1seq__DOT__currentstate))) {
        if ((0U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 0U;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 1U;
            }
        } else if ((1U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 1U;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 2U;
            }
        } else if ((2U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 3U;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 3U;
            }
        } else if ((3U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 7U;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 4U;
            }
        } else if ((4U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 0xfU;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 5U;
            }
        } else if ((5U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 0x1fU;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 6U;
            }
        } else if ((6U == vlSelf->f1seq__DOT__currentstate)) {
            vlSelf->dout = 0x3fU;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 7U;
            }
        } else {
            vlSelf->dout = 0x7fU;
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 8U;
            }
        }
    } else if ((8U == vlSelf->f1seq__DOT__currentstate)) {
        vlSelf->dout = 0xffU;
        if (vlSelf->en) {
            vlSelf->f1seq__DOT__nextstate = 0U;
        }
    } else {
        vlSelf->dout = 0U;
        vlSelf->f1seq__DOT__nextstate = 0U;
    }
}

VL_ATTR_COLD void Vf1seq___024root___eval_initial(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__en = vlSelf->en;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vf1seq___024root___eval_settle(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___eval_settle\n"); );
    // Body
    Vf1seq___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vf1seq___024root___final(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___final\n"); );
}

VL_ATTR_COLD void Vf1seq___024root___ctor_var_reset(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->dout = VL_RAND_RESET_I(8);
    vlSelf->f1seq__DOT__currentstate = 0;
    vlSelf->f1seq__DOT__nextstate = 0;
}
