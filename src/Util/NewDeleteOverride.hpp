#pragma once
#include <cstddef>
#include <new>
#include "Util/Exports.hpp"

void* operator new(std::size_t size)
{
   return malloc(size);
}

void* operator new(std::size_t size, const std::nothrow_t&) noexcept
{
   return malloc(size);
}

void* operator new(std::size_t size, std::size_t align)
{
   return memalign(align, size);
}

void* operator new(std::size_t size, std::size_t align, const std::nothrow_t&) noexcept
{
   return memalign(align, size);
}

void* operator new[](std::size_t size)
{
   return malloc(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) noexcept
{
   return malloc(size);
}

void* operator new[](std::size_t size, std::size_t align)
{
   return operator new(size, align);
}

void* operator new[](std::size_t size, std::size_t align, const std::nothrow_t&) noexcept
{
   return operator new(size, align);
}

void operator delete(void* mem) noexcept
{
   free(mem);
}

void operator delete(void* mem, const std::nothrow_t&) noexcept
{
   free(mem);
}

void operator delete(void* ptr, void*)
{
   return operator delete(ptr);
}

void operator delete(void* ptr, std::size_t)
{
   return operator delete(ptr);
}

void operator delete(void* ptr, std::size_t, const std::nothrow_t&) noexcept
{
   return operator delete(ptr);
}

void operator delete(void* ptr, std::size_t, void*)
{
   return operator delete(ptr);
}

void operator delete[](void* mem) noexcept
{
   free(mem);
}

void operator delete[](void* mem, const std::nothrow_t&) noexcept
{
   free(mem);
}

void operator delete[](void* ptr, void* ptr2)
{
   return operator delete(ptr, ptr2);
}

void operator delete[](void* ptr, std::size_t align)
{
   return operator delete(ptr, align);
}

void operator delete[](void* ptr, std::size_t align, const std::nothrow_t&) noexcept
{
   return operator delete(ptr, align);
}

void operator delete[](void* ptr, std::size_t align, void*)
{
   return operator delete(ptr, align);
}
