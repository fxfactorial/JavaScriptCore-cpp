#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "context.h"

Context::Context()
{
  std::cout << "Hello, created Context\n";
}
