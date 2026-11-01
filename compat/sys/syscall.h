#pragma once
// Sony SDK system_call_N names mapped onto the PS3DK lv2 syscall macros.
#include <sys/lv2_syscall.h>

#define system_call_0(n)                      lv2syscall0(n)
#define system_call_1(n, a1)                  lv2syscall1(n, a1)
#define system_call_2(n, a1, a2)              lv2syscall2(n, a1, a2)
#define system_call_3(n, a1, a2, a3)          lv2syscall3(n, a1, a2, a3)
#define system_call_4(n, a1, a2, a3, a4)      lv2syscall4(n, a1, a2, a3, a4)
#define system_call_5(n, a1, a2, a3, a4, a5)  lv2syscall5(n, a1, a2, a3, a4, a5)
#define system_call_6(n, a1, a2, a3, a4, a5, a6) lv2syscall6(n, a1, a2, a3, a4, a5, a6)

#ifndef SYS_TTY_WRITE
#define SYS_TTY_WRITE 403
#endif
