#include <iostream>
#include <string>

#ifdef __APPLE__
#include <JavaScriptCore/JavaScriptCore.h>
#else
#include <JavaScriptCore/JavaScript.h>
#endif

#include "context.h"
#include "value.h"
#include "virtual_machine.h"

jsc::Context::Context() :
  m_virtual_machine(new VirtualMachine),
  m_context(NULL)
{
  m_context =
    JSGlobalContextCreateInGroup(m_virtual_machine->m_group, NULL);
  m_virtual_machine->add_context(this, m_context);
}

jsc::Context::~Context()
{
  JSGlobalContextRelease(m_context);
}

jsc::Context::Context(VirtualMachine *const vm)
{

}

jsc::Value*
jsc::Context::evaluate_script(std::string script,
			      std::string source_url="")
{
  JSValueRef exceptionValue = nullptr;
  JSStringRef scriptJS = JSStringCreateWithUTF8CString(script.c_str());
  JSStringRef sourceURLJS =
    source_url == "" ? nullptr : JSStringCreateWithUTF8CString(source_url.c_str());
  JSValueRef result =
    JSEvaluateScript(m_context, scriptJS, nullptr, sourceURLJS, 0, &exceptionValue);
  if (sourceURLJS)
    JSStringRelease(sourceURLJS);

  JSStringRelease(scriptJS);

  // if (exceptionValue)
  //   return [self valueFromNotifyException:exceptionValue];

  // return [JSValue valueWithJSValueRef:result inContext:self];
  return nullptr;
}
