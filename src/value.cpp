#include <iostream>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "enum.h"
#include "value.h"
#include "context.h"

jsc::Value::Value (jsc::Context *ctx) :
  context(ctx)
{

}

jsc::Value::Value(JavaScript_t t)
{
  switch (t) {
  case JavaScript_t::New_object:
    std::cout << "Asked for a new object\n";
    break;
  case JavaScript_t::New_array:
    std::cout << "Asked for a new array\n";
    break;
  }
}

jsc::Value::~Value () { }
