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
  m_context_cache(std::map<JSGlobalContextRef, Context*>())
{
}

jsc::VirtualMachine::~VirtualMachine()
{
  JSContextGroupRelease(m_group);
  std::cout << "Deleted VirtualMachine\n";
}

void
jsc::VirtualMachine::add_context(Context *c, JSGlobalContextRef glbctx)
{
  m_context_cache[glbctx] = c;
}

jsc::Context*
jsc::VirtualMachine::context_from_global_context(JSGlobalContextRef ctx)
{
  return m_context_cache[ctx];
}
