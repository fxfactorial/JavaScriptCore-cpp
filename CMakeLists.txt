cmake_minimum_required(VERSION 2.8.12)
project(JavaScriptCore-C++)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB SOURCES "src/*.cpp")

#Generate the shared library from the sources
add_library(JavaScriptCore-C++ SHARED ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(JavaScriptCore-C++ PUBLIC "/usr/include/webkitgtk-3.0")
TARGET_LINK_LIBRARIES(JavaScriptCore-C++
  # Our needed libraries
  javascriptcoregtk-3.0
  BlocksRuntime)

# Set the location for library installation -- i.e., /usr/lib in this
# case not really necessary in this example. Use "sudo make install"
# to apply
install(TARGETS JavaScriptCore-C++ DESTINATION /usr/lib)

# This is the Headers that will be installed as a public API
install(FILES

  include/JavaScriptCore-C++.h
  include/virtual_machine.h
  include/context.h

  DESTINATION
  include/JavaScriptCore-C++)
