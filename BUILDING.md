# Building Kagura Client V2

This project builds with **PS3DK**, a free open-source PS3 toolchain (GCC) that can make PS3 plugins (SPRX files). You do not need the Sony SDK. The old Visual Studio and Sony SNC route is still here: [docs/BUILDING-SNC.md](docs/BUILDING-SNC.md).

> **Honest status:** this PS3DK build was written without access to the PS3 compiler. The GitHub Actions workflow in `.github/workflows/build.yml` is its first real test. If a step fails, send the first error line to the maintainer.

## What you get

A successful build writes three files into `build/out/`:

| File | Use |
|---|---|
| `KaguraClientV2.fake.sprx` | For custom-firmware consoles (this is the one you normally want) |
| `KaguraClientV2.sprx` | Signed version, mainly for RPCS3 or signed hardware |
| `KaguraClientV2.prx` | Unsigned module, used to make the other two |

Getting the plugin into the game works as before. The old Visual Studio build ran `InjectSPRX.exe` or `loadSprx.exe` afterwards, and those tools are not part of this repository.

## The simple picture

You need three things: the **toolchain** (the compiler, built once and reused), **CMake and Ninja** (the build tools), and this **source code**. The script `scripts/build.sh` ties them together.

## Linux (Ubuntu 24.04)

1. Install the build tools (about 5 minutes):

```bash
sudo apt-get update
sudo apt-get install -y build-essential gcc-12 g++-12 cmake ninja-build texinfo bison flex libgmp-dev libmpfr-dev libmpc-dev libisl-dev zlib1g-dev libreadline-dev libncurses-dev libexpat1-dev libssl-dev libelf-dev python3 python3-dev git wget patch autoconf automake libtool zip unzip curl
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source "$HOME/.cargo/env"
```

2. Build the toolchain once. This takes about 40 minutes to an hour and a lot of disk space (around 15 GB while building):

```bash
git clone --branch v0.19.0 https://github.com/FirebirdTA01/PS3DK.git "$HOME/PS3DK"
cd "$HOME/PS3DK"
source scripts/env.sh
./scripts/bootstrap.sh
./scripts/build-spu-toolchain.sh
./scripts/build-ppu-toolchain.sh
./scripts/build-psl1ght.sh
./scripts/build-sdk.sh
./scripts/build-cell-stub-archives.sh
```

3. Get the plugin source and build it:

```bash
git clone https://github.com/SSMG64/KaguraClientV2.git "$HOME/KaguraClientV2"
cd "$HOME/KaguraClientV2"
source "$HOME/PS3DK/scripts/env.sh"
PS3DK_CMAKE_DIR="$HOME/PS3DK/cmake" ./scripts/build.sh Release
```

Use `Debug` instead of `Release` for a debug build. Next time, skip steps 1 and 2 and only run `source "$HOME/PS3DK/scripts/env.sh"` and step 3.

## Windows

**Option A: WSL2 (recommended).** Open PowerShell as administrator and run `wsl --install -d Ubuntu-24.04`, then follow the Linux steps inside the Ubuntu window. Work inside the Linux home folder, not under `/mnt/c`, because the compiler build is far slower there.

**Option B: the prebuilt Windows toolchain (no compiling of the compiler).**

1. Install CMake and Ninja, for example with Chocolatey: `choco install cmake ninja`.
2. Download the file named `ps3-sdk-v0.19.0-windows-x86_64.zip` from the [PS3DK releases page](https://github.com/FirebirdTA01/PS3DK/releases) and extract it to `C:\PS3DK`.
3. In a normal `cmd` window:

```cmd
setx PS3DK "C:\PS3DK"
```

4. Open a **new** `cmd` window, go to the Kagura folder, and run:

```cmd
call "%PS3DK%\setup.cmd"
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="%PS3DK%\cmake\ps3-ppu-toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

The CI job for this route is marked experimental until someone confirms it works.

## macOS

PS3DK says macOS is untested as a place to build the toolchain, so this project cannot promise a native macOS build. The reliable route is a Linux container or virtual machine on your Mac. For example, with Docker installed:

```bash
docker run --rm -it -v "$HOME/KaguraClientV2:/work" -w /work ubuntu:24.04 bash
```

Inside that window, follow the **Linux** steps above (the toolchain build happens inside the container, so keep the container's disk space in mind). Once someone confirms a native macOS build, this section can be updated.

## Automatic builds (CI)

`.github/workflows/build.yml` builds the toolchain on a GitHub runner (cached after the first run), tests it with PS3DK's own example plugin, builds Kagura in Debug and Release, and uploads the plugin files as downloadable artifacts. The first run takes about an hour because it builds the toolchain.

## If something goes wrong

| Message | What to do |
|---|---|
| `PS3DEV is not set` | Run `source "$HOME/PS3DK/scripts/env.sh"` in the same terminal first |
| `Could not find ps3-ppu-toolchain.cmake` | Set `PS3DK_CMAKE_DIR` to the `cmake` folder of your PS3DK checkout, as in Linux step 3 |
| `required PRX runtime artifact missing` | In the PS3DK folder, run `./scripts/build-runtime-lv2.sh` |
| A compile error in `src/` | Send the **first** error line, not the last. Later errors are often echoes of the first |

## Project notes

- `compat/` holds tiny stand-ins for Sony-only headers (`sys/syscall.h`, `ppu_intrinsics.h`, `fastmath.h`).
- Boost is no longer needed. The source never used it.
- The plugin needs the system modules the game already loads, so it links against PS3DK stub libraries, not Sony ones.
- Keep SDK files, keys and build output out of commits.
