#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "virtual_machine.h"

jsc::VirtualMachine::VirtualMachine()
{
  std::cout << "Hello, created Virtual Machine\n";
}
