#pragma once
// The few Sony ppu_intrinsics.h helpers this project uses, as GCC inline asm.
#define __sync()   __asm__ __volatile__("sync" ::: "memory")
#define __isync()  __asm__ __volatile__("isync" ::: "memory")
#define __dcbst(p) __asm__ __volatile__("dcbst 0,%0" :: "r"(p) : "memory")
#define __nop()    __asm__ __volatile__("nop")
