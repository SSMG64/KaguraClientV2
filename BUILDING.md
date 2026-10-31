# Building Kagura Client V2

This repository is a PlayStation 3 (PS3) SPRX project. Its Visual Studio solution is `KaguraClientSPRXV2.sln`, and its project is `src/Minecraft.vcxproj`. The project explicitly selects the **SNC** Visual Studio platform toolset and the **PS3** platform. It is not a standard Windows, Linux, or macOS C++ project, and a normal desktop C++ compiler is not a drop-in replacement for the PS3 toolchain.

This guide distinguishes the supported build path from options for people who develop on other operating systems. It does not assume that the proprietary PS3 SDK or SNC compiler is included in this repository.

## Requirements

A successful native build requires all of the following:

- Windows, normally Windows 10 or 11.
- A compatible Visual Studio installation with the C++ workload and MSBuild. The solution file is from the Visual Studio 2013 era, so newer Visual Studio versions may require compatibility adjustments.
- The SNC PS3 compiler and its Visual Studio integration, which provides the `SNC` platform toolset.
- A legally obtained and installed PS3 SDK, including the PPU headers, libraries, and build tools referenced by the project.
- Any third-party SDK/dependency files expected by the project. The Release configuration references a Boost include directory through `$(SDKS)boost_1_36_0`.
- The environment variables described below, adjusted to match the actual locations on your machine.

The PS3 SDK and SNC toolset are not distributed with this source archive. Use only SDK/toolchain packages you are authorized to use. Do not commit SDK files, credentials, console-specific keys, or licensed binaries to the repository.

## Windows: build with Visual Studio

1. Install Visual Studio with the **Desktop development with C++** workload and MSBuild.
2. Install the SNC PS3 toolset and the PS3 SDK using their authorized installers and the documentation supplied with those packages. Ensure the SNC Visual Studio integration is installed for the Visual Studio instance you intend to use.
3. Open `KaguraClientSPRXV2.sln` in that Visual Studio instance.
4. In the configuration/platform selector, choose either **Debug | PS3** or **Release | PS3**. Do not choose `x64`, `Win32`, or another desktop platform; this solution defines only `PS3` configurations.
5. If Visual Studio reports that the `SNC` platform toolset is missing, the SNC integration is not installed or is not registered with that Visual Studio instance. Installing the ordinary Microsoft C++ workload alone will not fix this.
6. Build the solution using **Build > Build Solution**. Review the Output window for the first compiler or linker error. Fix missing SDK paths or dependencies before interpreting later errors.

### Environment variables and SDK paths

The project file references these variables:

- `SN_PS3_PATH`: SNC toolchain installation directory. The project expects headers under `$(SN_PS3_PATH)\ppu\include\sn` and libraries under `$(SN_PS3_PATH)\ppu\lib\sn`.
- `SCE_PS3_ROOT`: PS3 SDK root. The project expects PPU and common headers under `target\ppu\include` and `target\common\include`, and libraries under `target\ppu\lib` and its subdirectories.
- `SDKS`: a parent directory used by the Release configuration to locate `boost_1_36_0`. The project concatenates this variable directly with `boost_1_36_0`, so set it with a trailing path separator if required by your installation, for example `D:\SDKs\`.

Use the exact directory layout installed by your toolchain. Do not copy the example paths literally unless they match your machine. You can set user-level environment variables through Windows **Environment Variables** settings, or set them for one PowerShell session, for example:

```powershell
$env:SN_PS3_PATH = 'C:\Path\To\SNC'
$env:SCE_PS3_ROOT = 'C:\Path\To\PS3SDK'
$env:SDKS = 'D:\SDKs\'
```

These PowerShell assignments last only for that terminal session and processes launched from it. They do not install the SDK or register the Visual Studio toolset.

### Build from a Visual Studio Developer PowerShell

Open **Developer PowerShell for Visual Studio** for the Visual Studio instance that has the SNC integration installed. Set the three environment variables above, then run:

```powershell
msbuild .\KaguraClientSPRXV2.sln /m /t:Build /p:Configuration=Debug /p:Platform=PS3 /v:minimal
```

For Release:

```powershell
msbuild .\KaguraClientSPRXV2.sln /m /t:Build /p:Configuration=Release /p:Platform=PS3 /v:minimal
```

If `msbuild` is not found, use Developer PowerShell or invoke `MSBuild.exe` by its full path from the Visual Studio installation. If MSBuild says the `SNC` toolset or its `.props`/`.targets` files cannot be found, repair the SNC Visual Studio integration rather than changing the project to use Microsoft's desktop compiler.

## Build output

The project sets its output directory to:

```text
bin\Debug-PS3\
bin\Release-PS3\
```

Intermediate files go under `bin-int\`. The exact output filename and whether additional post-build steps succeed depend on the installed toolchain and project configuration. The project has post-build commands that attempt to run `InjectSPRX.exe` for Debug and `loadSprx.exe` for Release if those executables exist in the target directory. These utilities are not supplied by this guide; check the build log if a post-build step fails.

A successful compile/link is not proof that the resulting SPRX is safe to load or compatible with a particular console, firmware, or runtime environment. Test only in an environment you own or are authorized to use, and retain the full build log when reporting problems.

## GitHub Actions CI

The workflow at `.github/workflows/build.yml` is designed for a **self-hosted Windows runner** labelled `self-hosted`, `windows`, and `ps3-sdk`. This is intentional: GitHub-hosted runners do not come with the proprietary SNC PS3 toolset or PS3 SDK, and the workflow cannot legally or reliably download and install them automatically.

To enable it:

1. Configure a Windows machine as a GitHub Actions self-hosted runner for the repository, following GitHub's official runner documentation.
2. Install Visual Studio/MSBuild, the authorized SNC toolset, and the PS3 SDK on that machine.
3. Register the runner with the labels `windows` and `ps3-sdk` in addition to its default `self-hosted` label.
4. Configure `SN_PS3_PATH`, `SCE_PS3_ROOT`, and `SDKS` as environment variables available to the runner service. Restart the runner service after changing machine-level variables.
5. Confirm that the runner account can access the SDK directories and invoke the correct MSBuild installation.
6. Trigger the **Build PS3 SPRX** workflow manually or push a commit. The workflow attempts Debug and Release builds and uploads matching build outputs as GitHub Actions artifacts.

Do not put licensed SDK contents into GitHub Actions caches or artifacts unless the applicable SDK licence explicitly permits that use. Keep the self-hosted runner isolated from untrusted pull-request code: a workflow that compiles repository content on a machine with licensed SDK files has access to that machine's environment and permissions.

## Linux

There is no configured Linux build system in this repository. The checked-in solution is an MSBuild C++ project that depends on the Windows Visual Studio SNC integration and SDK paths. GCC or Clang on Linux cannot directly build this project as configured, and replacing SNC with a generic compiler is not a valid substitute for the PS3 PPU toolchain.

Practical options from a Linux workstation:

- Build on a separate Windows machine that has the required SNC toolset and SDK, using the Windows instructions above.
- Use a Windows virtual machine only if you can lawfully install and use the required Visual Studio integration and licensed SDK in that VM.
- Use the repository's self-hosted GitHub Actions runner and retrieve the workflow artifact after a successful run.

Linux can still be used for editing, Git operations, and source inspection. A native Linux build would require a separately supported, compatible PS3 PPU toolchain and a maintained build configuration for it; neither is provided here.

## macOS

There is no configured macOS build system in this repository either. Xcode/Clang does not provide the SNC PS3 platform toolset, and the project depends on Windows-specific Visual Studio integration. Use a properly licensed Windows build machine or the self-hosted CI runner. A Windows virtual machine is another option only where supported by the host hardware and permitted by the relevant toolchain licences.

macOS can be used for editing and Git operations, but a native macOS build is not supported by the current project files.

## Troubleshooting

- **MSB8020 / missing `SNC` toolset:** install or repair the SNC Visual Studio integration for the exact Visual Studio instance running MSBuild.
- **Missing `SN_PS3_PATH` or `SCE_PS3_ROOT` files:** check the environment variable values and confirm that the expected SDK directory structure exists.
- **Missing Boost headers in Release:** verify `SDKS` and the `boost_1_36_0` directory expected by the project. Do not assume a modern Boost version is source-compatible with this legacy code.
- **Linker errors for PS3 libraries:** confirm that the installed SDK contains the library files referenced in `src/Minecraft.vcxproj`, and that the selected configuration/platform is `Debug|PS3` or `Release|PS3`.
- **Post-build utility failure:** inspect whether `InjectSPRX.exe` or `loadSprx.exe` is expected in the output directory and whether it is compatible with the installed environment.
- **CI cannot find MSBuild:** install the Visual Studio C++ build tools on the self-hosted runner and ensure the runner service can locate them. The workflow also attempts to locate MSBuild through `vswhere`.
- **CI cannot find the SDK/toolset:** verify the runner service's environment variables, installed SNC integration, and runner labels. A GitHub-hosted runner will not gain these dependencies simply by changing YAML.

## Support boundaries

The repository currently documents a Windows/MSBuild/SNC build path. It does not contain a portable CMake or Makefile build, a Linux/macOS SNC toolchain, or the proprietary SDK installers. Do not treat a successful lint or CodeQL run as a successful PS3 build; only a build performed with the required toolchain can verify compilation and linking.
