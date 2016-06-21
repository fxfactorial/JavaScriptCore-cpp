JavaScriptCore-C++
=====================

A `C++` API to `JavaScriptCore` freely copying the interface of
Apple's `Objective-C` API to `JavaScriptCore`.

# Installation, usage

You'll need to have `JavaScriptCore` installed, on `ubuntu` do:

```shell
$ sudo aptitude install libjavascriptcoregtk-3.0-dev libblocksruntime0
```

Then:

```shell
$ cmake .
$ make
```

and if interested in installing:

```shell
$ sudo make install
```

and when using in your library:

```shell
$ clang++ -lJavaScriptCore-C++ -I/usr/include/webkitgtk-3.0 test.cpp
```
