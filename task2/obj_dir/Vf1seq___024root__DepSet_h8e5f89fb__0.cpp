// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1seq.h for the primary calling header

#include "verilated.h"

#include "Vf1seq___024root.h"

VL_INLINE_OPT void Vf1seq___024root___sequent__TOP__0(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->f1seq__DOT__currentstate = 0U;
    } else if (vlSelf->en) {
        vlSelf->f1seq__DOT__currentstate = vlSelf->f1seq__DOT__nextstate;
    }
    vlSelf->dout = (((((((((0U == vlSelf->f1seq__DOT__currentstate) 
                           | (1U == vlSelf->f1seq__DOT__currentstate)) 
                          | (2U == vlSelf->f1seq__DOT__currentstate)) 
                         | (3U == vlSelf->f1seq__DOT__currentstate)) 
                        | (4U == vlSelf->f1seq__DOT__currentstate)) 
                       | (5U == vlSelf->f1seq__DOT__currentstate)) 
                      | (6U == vlSelf->f1seq__DOT__currentstate)) 
                     | (7U == vlSelf->f1seq__DOT__currentstate))
                     ? ((0U == vlSelf->f1seq__DOT__currentstate)
                         ? 0U : ((1U == vlSelf->f1seq__DOT__currentstate)
                                  ? 1U : ((2U == vlSelf->f1seq__DOT__currentstate)
                                           ? 3U : (
                                                   (3U 
                                                    == vlSelf->f1seq__DOT__currentstate)
                                                    ? 7U
                                                    : 
                                                   ((4U 
                                                     == vlSelf->f1seq__DOT__currentstate)
                                                     ? 0xfU
                                                     : 
                                                    ((5U 
                                                      == vlSelf->f1seq__DOT__currentstate)
                                                      ? 0x1fU
                                                      : 
                                                     ((6U 
                                                       == vlSelf->f1seq__DOT__currentstate)
                                                       ? 0x3fU
                                                       : 0x7fU)))))))
                     : ((8U == vlSelf->f1seq__DOT__currentstate)
                         ? 0xffU : 0U));
}

VL_INLINE_OPT void Vf1seq___024root___combo__TOP__0(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___combo__TOP__0\n"); );
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
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 1U;
            }
        } else if ((1U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 2U;
            }
        } else if ((2U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 3U;
            }
        } else if ((3U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 4U;
            }
        } else if ((4U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 5U;
            }
        } else if ((5U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 6U;
            }
        } else if ((6U == vlSelf->f1seq__DOT__currentstate)) {
            if (vlSelf->en) {
                vlSelf->f1seq__DOT__nextstate = 7U;
            }
        } else if (vlSelf->en) {
            vlSelf->f1seq__DOT__nextstate = 8U;
        }
    } else if ((8U == vlSelf->f1seq__DOT__currentstate)) {
        if (vlSelf->en) {
            vlSelf->f1seq__DOT__nextstate = 0U;
        }
    } else {
        vlSelf->f1seq__DOT__nextstate = 0U;
    }
}

void Vf1seq___024root___eval(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->en) & (~ (IData)(vlSelf->__Vclklast__TOP__en))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vf1seq___024root___sequent__TOP__0(vlSelf);
    }
    Vf1seq___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__en = vlSelf->en;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vf1seq___024root___eval_debug_assertions(Vf1seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
