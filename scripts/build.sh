#!/usr/bin/env bash
# Build Kagura Client V2 with the open-source PS3DK toolchain (Linux, WSL, Docker).
set -euo pipefail

cd "$(dirname "$0")/.."

TYPE="${1:-Release}"
BUILD_DIR="${BUILD_DIR:-build}"
ENV_FILE="${PS3DK_ROOT:-$HOME/ps3dk-toolchain}/env.sh"

if [ -z "${PS3DEV:-}" ] && [ -f "$ENV_FILE" ]; then
    # shellcheck disable=SC1090
    source "$ENV_FILE"
fi

if [ -z "${PS3DEV:-}" ]; then
    echo "PS3DK is not loaded. Run bash scripts/setup-ps3dk.sh once, then try again." >&2
    exit 1
fi

SDK="${PS3DK:-$PS3DEV/ps3dk}"
TOOLCHAIN=""
for dir in "${PS3DK_CMAKE_DIR:-}" "${PS3_TOOLCHAIN_ROOT:-}/cmake" "$SDK/cmake" "$SDK/../cmake" "$PS3DEV/cmake"; do
    if [ -n "$dir" ] && [ -f "$dir/ps3-ppu-toolchain.cmake" ]; then
        TOOLCHAIN="$dir/ps3-ppu-toolchain.cmake"
        break
    fi
done

if [ -z "$TOOLCHAIN" ]; then
    echo "Could not find ps3-ppu-toolchain.cmake." >&2
    echo "Set PS3DK_CMAKE_DIR to the cmake folder of your PS3DK checkout." >&2
    exit 1
fi

echo "Toolchain file: $TOOLCHAIN"
cmake -S . -B "$BUILD_DIR" -G Ninja -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" -DCMAKE_BUILD_TYPE="$TYPE"
cmake --build "$BUILD_DIR"
echo "Done. Look in $BUILD_DIR/out/ for KaguraClientV2.prx, .sprx and .fake.sprx"
