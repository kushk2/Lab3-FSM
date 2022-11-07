// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1seq.h for the primary calling header

#include "verilated.h"

#include "Vf1seq__Syms.h"
#include "Vf1seq___024root.h"

void Vf1seq___024root___ctor_var_reset(Vf1seq___024root* vlSelf);

Vf1seq___024root::Vf1seq___024root(Vf1seq__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vf1seq___024root___ctor_var_reset(this);
}

void Vf1seq___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vf1seq___024root::~Vf1seq___024root() {
}
