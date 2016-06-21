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

class Context;

class VirtualMachine {
private:
  JSContextGroupRef m_group;
  std::map<JSGlobalContextRef, Context> m_context_cache;

public:
  VirtualMachine();
};


#endif
