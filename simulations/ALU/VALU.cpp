// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

VL_CTOR_IMP(VALU) {
    VALU__Syms* __restrict vlSymsp = __VlSymsp = new VALU__Syms(this, name());
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU::__Vconfigure(VALU__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VALU::~VALU() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/ALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/ALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__1\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT__b_in_internal = (0xffU & ((IData)(vlTOPp->inverted)
                                                 ? 
                                                (~ (IData)(vlTOPp->b_in))
                                                 : (IData)(vlTOPp->b_in)));
    if ((1U == (IData)(vlTOPp->op))) {
        vlTOPp->carry_out = (1U & ((((IData)(vlTOPp->a_in) 
                                     + (IData)(vlTOPp->ALU__DOT__b_in_internal)) 
                                    + (IData)(vlTOPp->carry_in)) 
                                   >> 8U));
    } else {
        if ((2U != (IData)(vlTOPp->op))) {
            if ((3U != (IData)(vlTOPp->op))) {
                if ((4U != (IData)(vlTOPp->op))) {
                    if ((5U == (IData)(vlTOPp->op))) {
                        vlTOPp->carry_out = (1U & ((IData)(vlTOPp->a_in) 
                                                   >> 1U));
                    } else {
                        if ((6U == (IData)(vlTOPp->op))) {
                            vlTOPp->carry_out = (1U 
                                                 & ((IData)(vlTOPp->a_in) 
                                                    >> 1U));
                        }
                    }
                }
            }
        }
    }
    vlTOPp->out = (0xffU & ((1U == (IData)(vlTOPp->op))
                             ? (((IData)(vlTOPp->a_in) 
                                 + (IData)(vlTOPp->ALU__DOT__b_in_internal)) 
                                + (IData)(vlTOPp->carry_in))
                             : ((2U == (IData)(vlTOPp->op))
                                 ? ((IData)(vlTOPp->a_in) 
                                    & (IData)(vlTOPp->b_in))
                                 : ((3U == (IData)(vlTOPp->op))
                                     ? ((IData)(vlTOPp->a_in) 
                                        ^ (IData)(vlTOPp->b_in))
                                     : ((4U == (IData)(vlTOPp->op))
                                         ? ((IData)(vlTOPp->a_in) 
                                            | (IData)(vlTOPp->b_in))
                                         : ((5U == (IData)(vlTOPp->op))
                                             ? (0xffU 
                                                & ((IData)(vlTOPp->a_in) 
                                                   >> 2U))
                                             : ((6U 
                                                 == (IData)(vlTOPp->op))
                                                 ? 
                                                (0xffU 
                                                 & ((0x3fffffc0U 
                                                     & ((IData)(vlTOPp->carry_in) 
                                                        << 6U)) 
                                                    | ((IData)(vlTOPp->a_in) 
                                                       >> 2U)))
                                                 : 0U)))))));
    vlTOPp->zero = (1U & (~ (IData)((0U != (IData)(vlTOPp->out)))));
    vlTOPp->overflow = (1U & (((((IData)(vlTOPp->a_in) 
                                 & (IData)(vlTOPp->ALU__DOT__b_in_internal)) 
                                >> 7U) & (~ ((IData)(vlTOPp->out) 
                                             >> 7U))) 
                              | (((~ ((IData)(vlTOPp->a_in) 
                                      >> 7U)) & (~ 
                                                 ((IData)(vlTOPp->ALU__DOT__b_in_internal) 
                                                  >> 7U))) 
                                 & ((IData)(vlTOPp->out) 
                                    >> 7U))));
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VALU::_eval_initial(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_initial\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::final\n"); );
    // Variables
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::_eval_settle(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_settle\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((op & 0xf0U))) {
        Verilated::overWidthError("op");}
    if (VL_UNLIKELY((inverted & 0xfeU))) {
        Verilated::overWidthError("inverted");}
    if (VL_UNLIKELY((carry_in & 0xfeU))) {
        Verilated::overWidthError("carry_in");}
}
#endif  // VL_DEBUG

void VALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_ctor_var_reset\n"); );
    // Body
    a_in = VL_RAND_RESET_I(8);
    b_in = VL_RAND_RESET_I(8);
    op = VL_RAND_RESET_I(4);
    inverted = VL_RAND_RESET_I(1);
    carry_in = VL_RAND_RESET_I(1);
    out = VL_RAND_RESET_I(8);
    carry_out = VL_RAND_RESET_I(1);
    zero = VL_RAND_RESET_I(1);
    overflow = VL_RAND_RESET_I(1);
    ALU__DOT__b_in_internal = VL_RAND_RESET_I(8);
}
