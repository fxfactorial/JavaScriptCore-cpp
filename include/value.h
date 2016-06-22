/* -*- c++ -*- */
#ifndef VALUE_H
#define VALUE_H

#include "context.h"
#include "enum.h"

namespace jsc {

  BETTER_ENUM(JavaScript_t, char, New_object, New_array)

  class Context;

  class Value {
  public:
    Value(bool, Context *);
    Value(double, Context *);
    Value(int32_t, Context *);
    Value(uint32_t, Context *);
    Value(Context*);
    Value(JavaScript_t);
    ~Value();
    Context *context;
  };
}
#endif
