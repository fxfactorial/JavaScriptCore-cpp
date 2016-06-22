/* -*- c++ -*- */
#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <vector>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "virtual_machine.h"
#include "value.h"

namespace jsc {

  class VirtualMachine;
  class Value;

  class Context {
  private:
    VirtualMachine *m_virtual_machine;
    JSGlobalContextRef m_context;

  public:
    Context(void);
    ~Context(void);
    Context(VirtualMachine*);
    Value* evaluate_script(std::string, std::string);
    Context* current_context(void) const;
    Value* current_callee(void) const;
    Value* current_this(void) const ;
    std::vector<Value> current_arguments(void) const;

    Value *global_object;
    Value *exception;
    void(^exception_handler) (Context *ctx, Value *exception);

  };
}
#endif
