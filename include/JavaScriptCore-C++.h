/* -*- c++ -*- */

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

namespace jsc
{
  class VirtualMachine {
  public:
    VirtualMachine();
  };
}
