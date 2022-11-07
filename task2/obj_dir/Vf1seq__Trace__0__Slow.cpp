// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vf1seq__Syms.h"


VL_ATTR_COLD void Vf1seq___024root__trace_init_sub__TOP__0(Vf1seq___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"en", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"clk", false,-1);
    tracep->declBus(c+4,"dout", false,-1, 7,0);
    tracep->pushNamePrefix("f1seq ");
    tracep->declBit(c+1,"en", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"clk", false,-1);
    tracep->declBus(c+4,"dout", false,-1, 7,0);
    tracep->declBus(c+5,"currentstate", false,-1, 31,0);
    tracep->declBus(c+6,"nextstate", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vf1seq___024root__trace_init_top(Vf1seq___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root__trace_init_top\n"); );
    // Body
    Vf1seq___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vf1seq___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vf1seq___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vf1seq___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vf1seq___024root__trace_register(Vf1seq___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vf1seq___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vf1seq___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vf1seq___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vf1seq___024root__trace_full_sub_0(Vf1seq___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vf1seq___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root__trace_full_top_0\n"); );
    // Init
    Vf1seq___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf1seq___024root*>(voidSelf);
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vf1seq___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vf1seq___024root__trace_full_sub_0(Vf1seq___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1seq___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->en));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->clk));
    bufp->fullCData(oldp+4,(vlSelf->dout),8);
    bufp->fullIData(oldp+5,(vlSelf->f1seq__DOT__currentstate),32);
    bufp->fullIData(oldp+6,(vlSelf->f1seq__DOT__nextstate),32);
}