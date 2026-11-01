cmake_minimum_required(VERSION 3.20)
project(KaguraClientV2 C CXX ASM)

# Provided by the PS3DK toolchain file, see BUILDING.md.
include(ps3-self)

add_executable(kagura
    src/Menu/Main.cpp
    src/Util/FileSystem.cpp
    src/Util/SystemCalls.cpp
    compat/ps3dk_runtime.cpp)

# compat/ goes first so its Sony-name shims win over any same-named header.
target_include_directories(kagura BEFORE PRIVATE compat)
target_include_directories(kagura PRIVATE src)
target_compile_features(kagura PRIVATE cxx_std_17)

# The Sony build has C++ exceptions and RTTI off, and a PRX cannot link their runtime.
target_compile_options(kagura PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    "$<$<COMPILE_LANGUAGE:CXX>:SHELL:-include ${CMAKE_CURRENT_SOURCE_DIR}/compat/ps3dk_prefix.h>")

target_compile_definitions(kagura PRIVATE
    KAGURA_PS3DK=1
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Debug>:__CELL_ASSERT__>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>)

# Stub libraries for the system modules the game already has loaded.
target_link_libraries(kagura PRIVATE
    sysutil_np_stub
    net_stub
    netctl_stub
    http_stub
    http_util_stub
    sysutil_stub
    sysmodule_stub
    io_stub
    fs_stub
    lv2_stub
    c_stub)

# NAME and VERSION are required by PS3DK v0.19.0 (the module info).
set(KAGURA_OUT "${CMAKE_BINARY_DIR}/out")
file(MAKE_DIRECTORY "${KAGURA_OUT}")
ps3_add_prx(kagura
    NAME Minecraft
    VERSION 1.1
    OUTPUT "${KAGURA_OUT}/KaguraClientV2.prx"
    SIGN)
