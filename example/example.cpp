#include <JavaScriptCore-C++/JavaScriptCore-C++.h>

int main(void)
{
  auto test_one = [](){
    std::unique_ptr<jsc::Context>(new jsc::Context);
  };

  auto test_two = [](){
    std::unique_ptr<jsc::Value>(new jsc::Value(jsc::JavaScript_t::New_object));
    std::unique_ptr<jsc::Value>(new jsc::Value(jsc::JavaScript_t::New_array));
  };
  test_one();
  test_two();
  return 0;
}
