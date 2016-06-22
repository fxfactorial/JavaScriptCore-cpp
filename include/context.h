/* -*- c++ -*- */
#ifndef CONTEXT_H
#define CONTEXT_H

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "virtual_machine.h"

namespace jsc {

  class VirtualMachine;

  class Context {
  private:
    VirtualMachine *m_virtual_machine;
    JSGlobalContextRef m_context;

  public:
    Context();
  };
}
#endif
