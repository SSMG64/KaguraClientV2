// Stand-ins for runtime pieces a PS3 module cannot link (no exceptions, no TLS).
#include <bits/functexcept.h>

extern "C" {
// Empty hooks for libstdc++ transactional memory, never called.
void _ITM_RU1() {}
void _ITM_RU4() {}
void _ITM_addUserCommitAction() {}
void _ITM_memcpyRnWt() {}
void _ITM_memcpyRtWn() {}
void _ZGTtdlPv() {}
void _ZGTtnaj() {}

// Weak reference from abstract-class vtables, a call here is a bug.
void __cxa_pure_virtual() { __builtin_trap(); }
}

// Library errors that would throw end here instead, as exceptions are off.
namespace std {
void __throw_bad_exception() { __builtin_trap(); }
void __throw_bad_alloc() { __builtin_trap(); }
void __throw_bad_array_new_length() { __builtin_trap(); }
void __throw_bad_cast() { __builtin_trap(); }
void __throw_bad_typeid() { __builtin_trap(); }
void __throw_logic_error(const char*) { __builtin_trap(); }
void __throw_domain_error(const char*) { __builtin_trap(); }
void __throw_invalid_argument(const char*) { __builtin_trap(); }
void __throw_length_error(const char*) { __builtin_trap(); }
void __throw_out_of_range(const char*) { __builtin_trap(); }
void __throw_out_of_range_fmt(const char*, ...) { __builtin_trap(); }
void __throw_runtime_error(const char*) { __builtin_trap(); }
void __throw_range_error(const char*) { __builtin_trap(); }
void __throw_overflow_error(const char*) { __builtin_trap(); }
void __throw_underflow_error(const char*) { __builtin_trap(); }
void __throw_system_error(int) { __builtin_trap(); }
void __throw_future_error(int) { __builtin_trap(); }
void __throw_bad_function_call() { __builtin_trap(); }
}
