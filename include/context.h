/* -*- c++ -*- */
#ifndef CONTEXT_H
#define CONTEXT_H

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "virtual_machine.h"

class VirtualMachine;

class Context {
private:
  VirtualMachine *m_virtual_machine;
public:
  Context();
};

#endif
