cmake_minimum_required(VERSION 3.20)
project(KaguraClientV2 C CXX ASM)

# Provided by the PS3DK toolchain file, see BUILDING.md.
include(ps3-self)

add_executable(kagura
    src/Menu/Main.cpp
    src/Util/FileSystem.cpp
    src/Util/SystemCalls.cpp)

# compat/ goes first so its Sony-name shims win over any same-named header.
target_include_directories(kagura BEFORE PRIVATE compat)
target_include_directories(kagura PRIVATE src)
target_compile_features(kagura PRIVATE cxx_std_17)

target_compile_definitions(kagura PRIVATE
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

# Module name and version come from SYS_MODULE_INFO in src/Menu/Main.cpp.
ps3_add_prx(kagura
    OUTPUT_NAME KaguraClientV2.prx
    OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
    SIGN)
