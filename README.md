# Kagura Client V2

Kagura Client V2 is a Minecraft PlayStation 3 (PS3) SPRX mod menu project written in C++ and organized as a Visual Studio solution. The codebase includes a menu layer, PS3-specific system and memory helpers, and Minecraft-related game code. It builds with the open-source PS3DK toolchain (GCC) through CMake, and the original Visual Studio and SNC project is kept for anyone with the Sony tools.

> **Build note:** the PS3DK build is new and its first real test is the GitHub Actions workflow. The legacy SNC build needs a properly licensed PS3 SDK and SNC toolchain, which are not included. See [BUILDING.md](BUILDING.md).

## Contents

- `KaguraClientSPRXV2.sln`: Visual Studio solution.
- `src/Minecraft.vcxproj`: project configuration. Although the project file is named `Minecraft.vcxproj`, the solution contains the `Minecraft` project and produces a PS3 dynamic library / SPRX-style target.
- `src/Menu/`: menu entry point and menu / HUD interfaces.
- `src/Games/`: game-specific functions, options, hooks, button definitions, and PS3 helpers.
- `src/Minecraft/`: Minecraft-related classes, including client, game, GUI, entity, item, level, network, rendering, and world code.
- `src/Util/`: filesystem, system-call, timing, export, and shared utility code.
- `BUILDING.md`: detailed platform and toolchain build notes.
- `.github/workflows/`: source linting, CodeQL and the PS3DK build workflow.
- `CMakeLists.txt`, `scripts/build.sh`, `compat/`: the PS3DK build and the shims for Sony-only headers.

## Requirements

A native build requires the following, installed separately:

1. Windows with a compatible Visual Studio installation and MSBuild.
2. Visual Studio C++ support and the SNC PS3 platform toolset integration.
3. A legally obtained PS3 SDK installation containing the PPU headers, libraries, and tools referenced by the project.
4. Any additional dependencies referenced by the project configuration. The Release configuration includes a Boost 1.36.0 include path through `$(SDKS)`.
5. Correct local environment variables and SDK paths. See [BUILDING.md](BUILDING.md) for setup details and troubleshooting.

A standard GCC or Clang installation on Linux or macOS is not a replacement for the SNC PS3 compiler and SDK. Those platforms may be used for editing and source review, but a supported native build requires a compatible PS3 development environment.

## Building

Open `KaguraClientSPRXV2.sln` in a Visual Studio installation that has the SNC PS3 toolset installed. Select one of the solution's configured platforms and configurations:

- `Debug | PS3`
- `Release | PS3`

Then build the solution using Visual Studio or MSBuild. The project configuration writes output under `bin/<Configuration>-<Platform>/` and intermediate files under `bin-int/<Configuration>-<Platform>/`.

For command-line examples, environment-variable setup, platform limitations, and troubleshooting, read [BUILDING.md](BUILDING.md) before attempting a build, and [docs/BUILDING-SNC.md](docs/BUILDING-SNC.md) for the legacy route. The precise commands can depend on the Visual Studio version, SDK installation, and SNC integration installed on the build machine.

## Project and CI status

The repository includes source hygiene and CodeQL checks, plus a build workflow that compiles the plugin with the PS3DK toolchain. A green build proves it compiles and links, not that it runs on a console. The legacy SNC build cannot run on GitHub-hosted runners.

## Source layout

```text
.
├── KaguraClientSPRXV2.sln
├── BUILDING.md
├── .github/
│   ├── dependabot.yml
│   └── workflows/
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
4. Test builds only in a correctly configured PS3 development environment.
5. Submit a pull request describing the change, the environment used to test it, and any limitations that remain.

Do not commit proprietary SDK files, licensed toolchain binaries, credentials, console-specific secrets, generated build output, or IDE caches.
