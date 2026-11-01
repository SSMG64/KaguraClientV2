# Building Kagura Client V2

There are two supported ways to build this project. They use the same source code, so pick the one that matches the tools you have.

| | Official route | Open-source route |
|---|---|---|
| Compiler | Sony SNC | GCC 12 from PS3DK |
| SDK | Sony PS3 SDK (licensed) | PS3DK (free, open source) |
| Project | `KaguraClientSPRXV2.sln` in Visual Studio | `CMakeLists.txt` with Ninja |
| Runs on | Windows | Linux, WSL2 on Windows, Docker on macOS (native Windows is experimental) |
| Guide | [docs/BUILDING-SNC.md](docs/BUILDING-SNC.md) | [docs/BUILDING-PS3DK.md](docs/BUILDING-PS3DK.md) |

**Which one should I use?**

- If you already have the Sony SDK and SNC set up, keep using the official route. Nothing about it changed.
- If you do not have the Sony tools (they are only available to approved developers), use the open-source route. It is free and needs no application.

## The quick version of the open-source route

On Linux or WSL2 (Ubuntu 24.04), after installing the build tools listed in [docs/BUILDING-PS3DK.md](docs/BUILDING-PS3DK.md):

```bash
git clone https://github.com/SSMG64/KaguraClientV2.git "$HOME/KaguraClientV2"
cd "$HOME/KaguraClientV2"
bash scripts/setup-ps3dk.sh
bash scripts/build.sh Release
```

The plugin files appear in `build/out/`. The `.fake.sprx` file is the one for custom-firmware consoles.

## Project notes

- `compat/` holds small stand-ins for Sony-only headers. Only the open-source route uses them.
- Boost is not needed by the open-source route. The source never used it.
- Keep SDK files, keys and build output out of commits.
