// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPIPELINE__SYMS_H_
#define VERILATED_VPIPELINE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpipeline.h"

// INCLUDE MODULE CLASSES
#include "Vpipeline___024root.h"
#include "Vpipeline_pipeline.h"
#include "Vpipeline_WB_STAGE.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vpipeline__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpipeline* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpipeline___024root            TOP;
    Vpipeline_pipeline             TOP__pipeline;
    Vpipeline_WB_STAGE             TOP__pipeline__my_WB_stage;

    // SCOPE NAMES
    VerilatedScope __Vscope_pipeline__my_WB_stage;

    // CONSTRUCTORS
    Vpipeline__Syms(VerilatedContext* contextp, const char* namep, Vpipeline* modelp);
    ~Vpipeline__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
