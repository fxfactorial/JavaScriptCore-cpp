#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "virtual_machine.h"

jsc::VirtualMachine::VirtualMachine() :
  m_group(JSContextGroupCreate()),
  m_context_cache(std::map<JSGlobalContextRef, Context>())
{
  std::cout << "Hello, created Virtual Machine\n";
}

jsc::VirtualMachine::~VirtualMachine()
{
  JSContextGroupRelease(m_group);
}
