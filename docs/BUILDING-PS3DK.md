# Building Kagura Client V2 with PS3DK (open source)

PS3DK is a free PS3 toolchain (GCC 12) that can make PS3 plugin modules (SPRX files). With it you can build this project without the Sony PS3 SDK and without the SNC compiler. It uses the same source files as the official route in [BUILDING-SNC.md](BUILDING-SNC.md). The only differences are small and sit behind a `KAGURA_PS3DK` switch (see [What is different in the source](#what-is-different-in-the-source)).

## What you get

A successful build writes three files into `build/out/`:

| File | Use |
|---|---|
| `KaguraClientV2.fake.sprx` | For custom-firmware consoles. This is the one you normally want |
| `KaguraClientV2.sprx` | The signed version. PS3DK notes that RPCS3 currently rejects it and that real hardware is untested, so use the fake one first |
| `KaguraClientV2.prx` | The unsigned module that the other two are made from |

Getting the plugin into the game works as it always did. The old Visual Studio build ran `InjectSPRX.exe` or `loadSprx.exe` afterwards, and those tools are not part of this repository.

## How far this has been tested

- Both `Debug` and `Release` compile, link and produce all three files with PS3DK v0.19.0 (checked on Linux, and by the GitHub Actions workflow).
- The plugin has **not** been run on a console or an emulator by the author of this port. The source patches game memory at fixed addresses, so a green build only proves that it compiles.
- The Windows (no WSL) route is built by an experimental CI job and has not been confirmed by hand.

## Linux and WSL2 (the main route)

You need an x86_64 Linux system. Ubuntu 24.04 is what the CI uses.

1. Install the build tools and Rust (about 5 minutes):

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake ninja-build patch python3 git curl xz-utils libgmp-dev libelf-dev libssl-dev zlib1g-dev
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source "$HOME/.cargo/env"
```

2. Get the source:

```bash
git clone https://github.com/SSMG64/KaguraClientV2.git "$HOME/KaguraClientV2"
cd "$HOME/KaguraClientV2"
```

3. Install the toolchain once. It downloads PS3DK v0.19.0 and its compilers (checked against fixed hashes), then sets up the SDK. This takes about 5 to 10 minutes and about 1.5 GB of disk:

```bash
./scripts/setup-ps3dk.sh
```

4. Build the plugin:

```bash
./scripts/build.sh Release
```

Use `Debug` instead of `Release` for a debug build. The script loads the toolchain for you. The next time, only step 4 is needed.

## Windows

**Option A: WSL2 (recommended).** Open PowerShell as administrator and run:

```powershell
wsl --install -d Ubuntu-24.04
```

Restart if asked, open the Ubuntu window and follow the Linux steps above. Work inside the Linux home folder, not under `/mnt/c`, because it is much faster there.

**Option B: the prebuilt Windows toolchain (experimental).** No Linux needed.

1. Install CMake and Ninja, for example with Chocolatey:

```cmd
choco install cmake ninja
```

2. Download `ps3-sdk-v0.19.0-windows-x86_64.zip` (about 630 MB) from the [PS3DK v0.19.0 release](https://github.com/FirebirdTA01/PS3DK/releases/tag/v0.19.0). Its SHA-256 should be `3b2a7adfcdde5607ef22c0520e2f5911706a5e2b5275c2035f14ad2193f880ae`. Check it in PowerShell with:

```powershell
Get-FileHash "$env:USERPROFILE\Downloads\ps3-sdk-v0.19.0-windows-x86_64.zip" -Algorithm SHA256
```

3. Extract it to `C:\ps3dk`, so that `C:\ps3dk\ps3-sdk-v0.19.0-windows-x86_64\setup.cmd` exists. Careful: the zip already contains one top-level folder, so do not add another one.

4. In a normal `cmd` window, set the install folder once:

```cmd
setx PS3DK "C:\ps3dk\ps3-sdk-v0.19.0-windows-x86_64"
```

5. Open a **new** `cmd` window, go to the Kagura folder and build:

```cmd
cd C:\Users\%USERNAME%\KaguraClientV2
call "%PS3DK%\setup.cmd"
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="%PS3DK%\cmake\ps3-ppu-toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## macOS

PS3DK does not support building natively on macOS, and its compilers are Linux x86_64 programs. The reliable way is a Linux container. With Docker Desktop installed, in Terminal:

```bash
git clone https://github.com/SSMG64/KaguraClientV2.git "$HOME/KaguraClientV2"
docker run --platform linux/amd64 --rm -it -v "$HOME/KaguraClientV2:/work" -w /work ubuntu:24.04 bash
```

Inside the container:

```bash
apt-get update
apt-get install -y build-essential cmake ninja-build patch python3 git curl ca-certificates xz-utils libgmp-dev libelf-dev libssl-dev zlib1g-dev
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source "$HOME/.cargo/env"
./scripts/setup-ps3dk.sh
./scripts/build.sh Release
```

The plugin files appear in `build/out/` inside your Kagura folder on the Mac. On Apple Silicon the container runs under emulation, so expect it to be slower.

## Automatic builds (CI)

`.github/workflows/build.yml` has three jobs:

- **Toolchain** installs PS3DK with `scripts/setup-ps3dk.sh` and caches it, so later runs skip the install.
- **Plugin (Debug) and Plugin (Release)** first build PS3DK's own example SPRX as a smoke test, then build Kagura and upload the plugin files as downloadable artifacts.
- **Plugin on Windows (experimental)** downloads the prebuilt Windows toolchain (hash checked) and builds Release. It may fail without blocking the other jobs.

## What is different in the source

The Sony route sees the original code. The PS3DK route defines `KAGURA_PS3DK` (in `CMakeLists.txt` only) and gets these changes:

- `compat/` holds small stand-ins for Sony-only headers: `sys/syscall.h` (the `system_call_N` names), `ppu_intrinsics.h` (`__sync`, `__isync`, `__dcbst`, `__nop`), `fastmath.h` and `sys/random_number.h`.
- `compat/ps3dk_runtime.cpp` and `compat/ps3dk_prefix.h` keep the C++ exception runtime out of the module. A PS3 module cannot contain it, and the Sony build had exceptions off as well.
- `src/Menu/Main.cpp` uses `module_start` and `module_stop` on PS3DK, in place of the `SYS_MODULE_*` macros.
- `src/Games/Hooking.h` makes the hook stubs at least 8 instructions long, because the hook code overwrites 8 instructions per stub.
- A few lines were made valid for GCC (missing `return`, address of a temporary, a name clash with `sleep`). They do the same thing under SNC.

## If something goes wrong

| Message | What to do |
|---|---|
| `PS3DK is not loaded` | Run `./scripts/setup-ps3dk.sh` once |
| `needs Linux x86_64` | Use WSL2 on Windows or Docker on macOS, see above |
| `missing: ...` from the setup script | Install what it lists, the Ubuntu command is in step 1 |
| `checksum mismatch` | The download was damaged. Run the script again |
| `Could not find ps3-ppu-toolchain.cmake` | Set `PS3DK_CMAKE_DIR` to the `cmake` folder of your PS3DK checkout |
| A compile error in `src/` | Send the **first** error line, not the last. Later errors are often echoes of the first |

To remove the toolchain, delete the `ps3dk-toolchain` folder in your home folder.
