#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "value.h"

jsc::Value::Value () {}

jsc::Value::~Value () {}
