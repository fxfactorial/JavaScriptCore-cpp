cmake_minimum_required(VERSION 2.8.12)
project(JavaScriptCore-C++)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB SOURCES "src/*.cpp")

#Generate the shared library from the sources
add_library(JavaScriptCore-C++ SHARED ${SOURCES})

if (APPLE)
  include_directories(/System/Library/Frameworks)
  find_library(JAVASCRIPTCORE_LIBRARY JavaScriptCore)
  mark_as_advanced(JAVASCRIPTCORE_LIBRARY)
  set(EXTRA_LIBS ${JAVASCRIPTCORE_LIBRARY})
  target_link_libraries(JavaScriptCore-C++ ${EXTRA_LIBS})
  install(TARGETS JavaScriptCore-C++ DESTINATION /usr/local/lib)
else ()
  TARGET_INCLUDE_DIRECTORIES(JavaScriptCore-C++ PUBLIC "/usr/include/webkitgtk-3.0")
  TARGET_LINK_LIBRARIES(JavaScriptCore-C++
    # Our needed libraries
    javascriptcoregtk-3.0
    BlocksRuntime)
  install(TARGETS JavaScriptCore-C++ DESTINATION /usr/lib)
endif()

# This is the Headers that will be installed as a public API
install(FILES

  include/JavaScriptCore-C++.h
  include/virtual_machine.h
  include/context.h

  DESTINATION
  include/JavaScriptCore-C++)
