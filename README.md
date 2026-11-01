# Kagura Client V2

Kagura Client V2 is a Minecraft PlayStation 3 (PS3) SPRX mod menu project written in C++. The codebase includes a menu layer, PS3-specific system and memory helpers, and Minecraft-related game code.

It can be built in two ways from the same source: the official route with Visual Studio, the Sony SNC compiler and the Sony PS3 SDK, or the open-source route with the free PS3DK toolchain (GCC) and CMake. See [BUILDING.md](BUILDING.md) to pick one.

## Contents

- `KaguraClientSPRXV2.sln`: Visual Studio solution.
- `src/Minecraft.vcxproj`: project configuration. Although the project file is named `Minecraft.vcxproj`, the solution contains the `Minecraft` project and produces a PS3 dynamic library / SPRX-style target.
- `src/Menu/`: menu entry point and menu / HUD interfaces.
- `src/Games/`: game-specific functions, options, hooks, button definitions, and PS3 helpers.
- `src/Minecraft/`: Minecraft-related classes, including client, game, GUI, entity, item, level, network, rendering, and world code.
- `src/Util/`: filesystem, system-call, timing, export, and shared utility code.
- `BUILDING.md`: how to choose a build route.
- `docs/BUILDING-SNC.md`: the official route (Visual Studio, SNC, Sony PS3 SDK).
- `docs/BUILDING-PS3DK.md`: the open-source route (PS3DK, CMake).
- `.github/workflows/`: source linting, CodeQL and the PS3DK build workflow.
- `CMakeLists.txt`, `scripts/`, `compat/`: the PS3DK build, its setup script and the stand-ins for Sony-only headers.

## Building

### Official route (Visual Studio, SNC, Sony PS3 SDK)

This needs Windows, Visual Studio with the SNC PS3 toolset integration, and a legally obtained PS3 SDK. Open `KaguraClientSPRXV2.sln`, select `Debug | PS3` or `Release | PS3` and build. Output goes under `bin/<Configuration>-<Platform>/` and intermediate files under `bin-int/<Configuration>-<Platform>/`. The Release configuration includes a Boost 1.36.0 include path through `$(SDKS)`. Full instructions: [docs/BUILDING-SNC.md](docs/BUILDING-SNC.md).

### Open-source route (PS3DK)

This needs no Sony software. On Linux or WSL2 (Ubuntu 24.04):

```bash
./scripts/setup-ps3dk.sh
./scripts/build.sh Release
```

The first command installs the toolchain once, the second builds the plugin into `build/out/`. Windows without WSL, macOS and the exact prerequisites are covered in [docs/BUILDING-PS3DK.md](docs/BUILDING-PS3DK.md).

## Project and CI status

The repository includes source hygiene and CodeQL checks, plus a build workflow that compiles the plugin with PS3DK in Debug and Release and uploads the result. A green build proves it compiles and links, not that it runs on a console. The official SNC build cannot run on GitHub-hosted runners.

## Source layout

```text
.
├── KaguraClientSPRXV2.sln
├── CMakeLists.txt
├── BUILDING.md
├── compat/
├── docs/
│   ├── BUILDING-PS3DK.md
│   └── BUILDING-SNC.md
├── scripts/
│   ├── build.sh
│   └── setup-ps3dk.sh
├── .github/
│   ├── dependabot.yml
│   └── workflows/
│       ├── build.yml
│       ├── codeql.yml
│       └── lint.yml
└── src/
    ├── Games/
    ├── Menu/
    ├── Minecraft/
    └── Util/
```

This is a representative overview, not an exhaustive listing of every source file.

## Safety and compatibility

This code contains PS3-specific memory and system-call functionality. Incorrect addresses, assumptions about game versions, or incompatible runtime environments can cause crashes or instability. Review the code and confirm compatibility with the exact game and console environment before testing. Keep backups of relevant data and avoid testing on systems or accounts you do not own or have permission to use.

## Contributing

1. Fork the repository and create a focused branch for your change.
2. Keep changes scoped and document any new dependencies or SDK assumptions.
3. Run the available lint workflow locally where practical and review CodeQL findings.
4. Test builds with either route, and keep the source working for both (changes that only one compiler accepts belong behind `KAGURA_PS3DK`).
5. Submit a pull request describing the change, the environment used to test it, and any limitations that remain.

Do not commit proprietary SDK files, licensed toolchain binaries, credentials, console-specific secrets, generated build output, or IDE caches.
