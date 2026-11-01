#!/usr/bin/env bash
# Build Kagura Client V2 with the open-source PS3DK toolchain (Linux, macOS, WSL).
set -euo pipefail

cd "$(dirname "$0")/.."

if [ -z "${PS3DEV:-}" ]; then
    echo "PS3DEV is not set. Load the toolchain first, for example: source ~/PS3DK/scripts/env.sh" >&2
    exit 1
fi

TYPE="${1:-Release}"
SDK="${PS3DK:-$PS3DEV/ps3dk}"

TOOLCHAIN=""
for dir in "${PS3DK_CMAKE_DIR:-}" "$SDK/cmake" "$SDK/../cmake" "$PS3DEV/cmake"; do
    if [ -n "$dir" ] && [ -f "$dir/ps3-ppu-toolchain.cmake" ]; then
        TOOLCHAIN="$dir/ps3-ppu-toolchain.cmake"
        break
    fi
done

if [ -z "$TOOLCHAIN" ]; then
    echo "Could not find ps3-ppu-toolchain.cmake." >&2
    echo "Set PS3DK_CMAKE_DIR to the cmake folder of your PS3DK checkout, for example: export PS3DK_CMAKE_DIR=\$HOME/PS3DK/cmake" >&2
    exit 1
fi

echo "Toolchain file: $TOOLCHAIN"
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" -DCMAKE_BUILD_TYPE="$TYPE"
cmake --build build
echo "Done. Look in build/out/ for KaguraClientV2.prx, .sprx and .fake.sprx"
