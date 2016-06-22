/* -*- c++ -*- */
#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include <map>

#include "context.h"

namespace jsc {

  class Context;

  class VirtualMachine {
  public:
    JSContextGroupRef m_group;
    VirtualMachine();
    ~VirtualMachine();
    void add_context(Context *, JSGlobalContextRef);
    Context* context_from_global_context(JSGlobalContextRef);
  private:
    std::map<JSGlobalContextRef, Context*> m_context_cache;
  };

}
#endif
