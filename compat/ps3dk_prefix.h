#pragma once
// Build std::string inside this module, the library copy drags in the exception runtime.
#include <bits/c++config.h>
#undef _GLIBCXX_EXTERN_TEMPLATE
#define _GLIBCXX_EXTERN_TEMPLATE 0
