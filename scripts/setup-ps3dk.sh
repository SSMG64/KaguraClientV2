#!/usr/bin/env bash
# Installs the PS3DK toolchain and SDK from the project's release files (Linux, WSL2).
set -euo pipefail

PS3DK_TAG=v0.19.0
PS3DK_COMMIT=2f3eca57f72a194777a561b5b1e9d64159cfffa0
SHA_PPU=ba42f04338220abaf59ffff2da5111df5fd88392532bc2b7e2393a0eb5be13a6
SHA_SPU=3a5acdb14bab277e86e027f50f834e92023cc6473c38ea5a06718ea36bb2a510
SHA_TOOLS=7ebd626576d19cc250d1bc4b94200bd20e4e7dbeef63b15dd0a528dd0dae217f

ROOT="${PS3DK_ROOT:-$HOME/ps3dk-toolchain}"
BASE="https://github.com/FirebirdTA01/PS3DK"
REL="$BASE/releases/download/$PS3DK_TAG"
TOOLS_FILE="ps3-sdk-tools-$PS3DK_TAG-linux-x86_64.tar.xz"
DONE="$ROOT/.installed-$PS3DK_TAG"

say() { printf '[setup] %s\n' "$*"; }
die() { printf '[setup] ERROR: %s\n' "$*" >&2; exit 1; }

if [ "$(uname -s)" != Linux ] || [ "$(uname -m)" != x86_64 ]; then
    die "needs Linux x86_64 (Windows: use WSL2, macOS: use Docker). See docs/BUILDING-PS3DK.md."
fi

if [ -f "$DONE" ]; then
    say "PS3DK $PS3DK_TAG is already installed in $ROOT"
    exit 0
fi

missing=()
for c in git curl tar xz sha256sum make gcc g++ cmake ninja patch python3 cargo; do
    command -v "$c" >/dev/null 2>&1 || missing+=("$c")
done
for h in gmp.h libelf.h openssl/evp.h zlib.h; do
    echo "#include <$h>" | gcc -E -x c - >/dev/null 2>&1 || missing+=("header:$h")
done
if [ "${#missing[@]}" -gt 0 ]; then
    say "missing: ${missing[*]}"
    die "on Ubuntu run: sudo apt-get install -y build-essential cmake ninja-build patch python3 git curl xz-utils libgmp-dev libelf-dev libssl-dev zlib1g-dev (and install Rust from https://rustup.rs)"
fi

mkdir -p "$ROOT/dl"

fetch() {
    local f="$ROOT/dl/$1"
    if [ -f "$f" ] && echo "$2  $f" | sha256sum -c --status; then
        return
    fi
    say "downloading $1"
    curl -fL --retry 4 --retry-delay 5 -o "$f.part" "$REL/$1"
    mv "$f.part" "$f"
    echo "$2  $f" | sha256sum -c --status || die "checksum mismatch for $1"
}

fetch ps3dev-ppu.tar.xz "$SHA_PPU"
fetch ps3dev-spu.tar.xz "$SHA_SPU"
fetch "$TOOLS_FILE" "$SHA_TOOLS"

say "unpacking the PPU and SPU compilers"
rm -rf "$ROOT/ps3dev"
tar -xJf "$ROOT/dl/ps3dev-ppu.tar.xz" -C "$ROOT"
tar -xJf "$ROOT/dl/ps3dev-spu.tar.xz" -C "$ROOT"

if [ ! -d "$ROOT/PS3DK/.git" ]; then
    say "fetching PS3DK $PS3DK_TAG"
    git clone -q --depth 1 --branch "$PS3DK_TAG" "$BASE.git" "$ROOT/PS3DK"
fi
[ "$(git -C "$ROOT/PS3DK" rev-parse HEAD)" = "$PS3DK_COMMIT" ] \
    || die "PS3DK $PS3DK_TAG is not the commit this script was tested with"

PSL_SRC="$ROOT/PS3DK/src/ps3dev/PSL1GHT"
PSL_COMMIT="$(sed -n 's/^PSL1GHT_COMMIT="\([0-9a-f]*\)".*/\1/p' "$ROOT/PS3DK/scripts/bootstrap.sh")"
[ -n "$PSL_COMMIT" ] || die "could not read the PSL1GHT commit from PS3DK"
if [ ! -d "$PSL_SRC/.git" ]; then
    say "fetching PSL1GHT"
    mkdir -p "$(dirname "$PSL_SRC")"
    git clone -q --depth 1 https://github.com/ps3dev/PSL1GHT.git "$PSL_SRC"
fi
git -C "$PSL_SRC" fetch -q --depth 1 origin "$PSL_COMMIT"
git -C "$PSL_SRC" checkout -q --detach "$PSL_COMMIT"

export PS3DEV="$ROOT/ps3dev"
export PS3_BUILD_ROOT="$ROOT/build"
cd "$ROOT/PS3DK"
# shellcheck disable=SC1091
source scripts/env.sh
mkdir -p "$PS3DEV"/{bin,psl1ght,portlibs} "$PS3_BUILD_ROOT"

run() { say "$*"; "$@"; }

run ./scripts/build-psl1ght.sh

say "installing the prebuilt host tools"
tools_tmp="$(mktemp -d)"
tar -xJf "$ROOT/dl/$TOOLS_FILE" -C "$tools_tmp"
for d in "$PS3DEV/bin" "$PS3DK/bin"; do
    install -d "$d"
    for t in "$tools_tmp"/*/bin/*; do
        install -m 0755 "$t" "$d/$(basename "$t")"
    done
done
rm -rf "$tools_tmp"

run ./scripts/build-sdk.sh --headers-only
run ./scripts/build-cell-stub-archives.sh
run ./scripts/build-sdk.sh --no-host-tools

cat > "$ROOT/env.sh" <<EOF
export PS3DEV="$PS3DEV"
source "$ROOT/PS3DK/scripts/env.sh"
EOF

rm -rf "$ROOT/dl" "$ROOT/build" "$ROOT/PS3DK/tools/target"
touch "$DONE"
say "done. Next: source $ROOT/env.sh"
