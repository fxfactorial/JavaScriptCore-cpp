#include <JavaScriptCore-C++/JavaScriptCore-C++.h>

void plain_test(void)
{
  jsc::Context ctx;

  auto on_heap = new jsc::Context();
}


int main(void)
{
  auto test_one = [](){
    auto handle = jsc::Context{};
  };

  auto test_two = [](){
    // auto foo = new jsc::Context();
    // delete foo;

    auto thing = std::unique_ptr<jsc::Context>(new jsc::Context);
  };

  // test_one();
  test_two();
  // plain_test();
  return 0;
}
