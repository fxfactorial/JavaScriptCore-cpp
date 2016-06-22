#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "context.h"
#include "value.h"

jsc::Context::Context()
{
  std::cout << "Alloc context\n";
  global_object = nullptr;
}

jsc::Context::~Context()
{
  std::cout << "Dealloc\n";
}

jsc::Context::Context(VirtualMachine *const vm)
{
  std::cout << "Hello world\n";
}

jsc::Value*
jsc::Context::evaluate_script(std::string script, std::string source_url="/")
{
  return nullptr;
}
