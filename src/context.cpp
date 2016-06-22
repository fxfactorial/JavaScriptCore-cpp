#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "context.h"

jsc::Context::Context() :
  m_virtual_machine(new VirtualMachine)
{ }
