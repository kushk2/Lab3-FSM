// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vf1seq.h for the primary calling header

#ifndef VERILATED_VF1SEQ___024ROOT_H_
#define VERILATED_VF1SEQ___024ROOT_H_  // guard

#include "verilated.h"

class Vf1seq__Syms;

class Vf1seq___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(clk,0,0);
    VL_OUT8(dout,7,0);
    CData/*0:0*/ __Vclklast__TOP__en;
    CData/*0:0*/ __Vclklast__TOP__rst;
    IData/*31:0*/ f1seq__DOT__currentstate;
    IData/*31:0*/ f1seq__DOT__nextstate;

    // INTERNAL VARIABLES
    Vf1seq__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vf1seq___024root(Vf1seq__Syms* symsp, const char* name);
    ~Vf1seq___024root();
    VL_UNCOPYABLE(Vf1seq___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
