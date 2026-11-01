# Building Kagura Client V2 with Sony SNC (legacy)

> This is the old Visual Studio and SNC route. The open-source route is in [BUILDING.md](../BUILDING.md).

This guide explains what is required to build Kagura Client V2, how to install and configure the publicly obtainable tools, how to build the supplied Visual Studio solution, and how to diagnose common errors. It is written for people who have not built a PlayStation 3 (PS3) project before.

> **Important limitation:** this repository is not a self-contained C++ project. The solution targets the PS3 platform and explicitly selects the proprietary **SNC** compiler toolset. A standard installation of Visual Studio, GCC, or Clang is not enough. You must already have legitimate access to a compatible PS3 SDK and SNC toolchain. Those proprietary packages are not included here, and this guide does not provide unofficial mirrors or redistributed copies.

## Contents

- [1. What you need](#1-what-you-need)
- [2. Get the source code](#2-get-the-source-code)
- [3. Install Visual Studio and MSBuild](#3-install-visual-studio-and-msbuild)
- [4. Obtain the PS3 SDK and SNC toolset](#4-obtain-the-ps3-sdk-and-snc-toolset)
- [5. Set up Boost for Release builds](#5-set-up-boost-for-release-builds)
- [6. Configure the environment variables](#6-configure-the-environment-variables)
- [7. Build in Visual Studio](#7-build-in-visual-studio)
- [8. Build from the command line](#8-build-from-the-command-line)
- [9. Find the output and understand post-build steps](#9-find-the-output-and-understand-post-build-steps)
- [10. Linux and macOS](#10-linux-and-macos)
- [11. Troubleshooting](#11-troubleshooting)
- [12. Security, licensing, and project boundaries](#12-security-licensing-and-project-boundaries)
- [13. Reference links](#13-reference-links)

## 1. What you need

A successful build requires all of the following:

1. **A Windows computer.** Windows 10 or 11 is the practical starting point, but compatibility also depends on the age of the SNC integration and PS3 SDK you have access to.
2. **Visual Studio with C++ build tools and MSBuild.** The solution is from the older Visual Studio project format era. A recent Visual Studio installation may work only if the SNC integration supports it; do not assume compatibility.
3. **The SNC PS3 compiler and Visual Studio integration.** The project file contains `<PlatformToolset>SNC</PlatformToolset>`. This toolset must be registered with the Visual Studio instance used to build the project.
4. **A compatible, lawfully obtained PS3 SDK.** The project references PS3 PPU headers and libraries from the SDK.
5. **Boost 1.36.0 headers for the Release configuration.** The Release configuration adds `$(SDKS)boost_1_36_0` to its include directories. Debug does not list that Boost include path in the checked-in project configuration.
6. **The environment variables described below**, set to match your actual installation folders.

The repository does not contain the proprietary SDK, SNC toolchain, or Boost dependency directory. Do not expect the solution to build immediately after cloning it.

## 2. Get the source code

Clone the repository using Git:

```powershell
git clone https://github.com/SSMG64/KaguraClientV2.git
cd KaguraClientV2
```

Alternatively, use GitHub's **Code → Download ZIP** option on the repository page, extract the archive, and open the extracted project directory. A ZIP download is sufficient for building; Git is only needed if you want to pull updates or contribute changes.

The important project files are:

- `KaguraClientSPRXV2.sln`: the Visual Studio solution.
- `src/Minecraft.vcxproj`: the C++ project and its build settings.
- `src/`: source code.
- `BUILDING.md`: this guide.

Run build commands from the directory containing `KaguraClientSPRXV2.sln`, unless a step says otherwise.

## 3. Install Visual Studio and MSBuild

### 3.1 Download from Microsoft

Use Microsoft's official [Visual Studio downloads page](https://visualstudio.microsoft.com/downloads/). The free Community edition may be sufficient for general Visual Studio development, subject to Microsoft's licence terms. If you need an older Visual Studio version for SNC compatibility, Microsoft's [older downloads page](https://visualstudio.microsoft.com/vs/older-downloads/) may require a qualifying Visual Studio subscription. Do not download modified installers from random file-hosting sites.

Read Microsoft's official [Visual Studio installation guide](https://learn.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=visualstudio) if you need screenshots or detailed installer instructions.

### 3.2 Select the C++ workload

1. Start the Visual Studio Installer.
2. Install Visual Studio, or select **Modify** for an existing installation.
3. Under **Workloads**, select **Desktop development with C++**.
4. Confirm that MSBuild and the C++ build tools are selected. Microsoft's [C++ Build Tools component reference](https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=vs-2022) describes the relevant components.
5. Complete installation and restart Windows if the installer requests it.

This provides Microsoft's build infrastructure. **It does not install the SNC PS3 toolset or the PS3 SDK.** Those are separate prerequisites.

### 3.3 Verify MSBuild is installed

Open **Developer PowerShell for Visual Studio** from the Windows Start menu. Choose the entry corresponding to the Visual Studio installation you intend to use. Run:

```powershell
msbuild -version
```

If PowerShell says that `msbuild` is not recognised, reopen the correct Developer PowerShell. If it is still unavailable, repair the Visual Studio C++ installation and consult Microsoft's [MSBuild documentation](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild?view=visualstudio).

## 4. Obtain the PS3 SDK and SNC toolset

### 4.1 Use an authorised source

The PS3 SDK and SNC compiler are proprietary developer tools. Start with the official [PlayStation Partners portal](https://partners.playstation.net/) and the documentation or support channel available to your authorised developer account. Access to legacy PS3 tools may be restricted and is not guaranteed. If you do not already have authorised access, there may be no public, official download available to you.

This guide deliberately does not link to unofficial SDK mirrors, repacks, leaked packages, or license circumvention instructions. Do not assume that a third-party archive is authentic, safe, complete, or legally redistributable.

### 4.2 Install the SDK and SNC integration

Follow the installation instructions supplied with the SDK/toolchain version you are authorised to use. The exact installer names and folder layout vary by release, so this guide cannot safely prescribe one universal path.

During setup, confirm that:

- The PS3 SDK is installed and its PPU headers and libraries are present.
- The SNC PPU compiler and its libraries are installed.
- The SNC Visual Studio integration or platform-toolset files are installed for the Visual Studio instance you will use.
- You know the actual SDK root and SNC toolchain root directories.

The project expects paths resembling the following, relative to the relevant roots:

| Variable | Paths expected by this project |
|---|---|
| `SN_PS3_PATH` | `ppu\include\sn` and `ppu\lib\sn` |
| `SCE_PS3_ROOT` | `target\ppu\include`, `target\common\include`, and libraries under `target\ppu\lib` |

If your authorised installation has a different layout, do not rename or move SDK files blindly. Check the documentation for that specific SDK release and update the project paths only if you understand the impact.

### 4.3 Confirm the toolset is available

Open `KaguraClientSPRXV2.sln` in the Visual Studio instance where you installed the integration. If Visual Studio reports that the `SNC` platform toolset is missing, the integration is either absent, incompatible, or not registered for that Visual Studio version. Installing Microsoft's standard C++ workload alone will not resolve that error.

Do not change `SNC` to `v143`, `v142`, or another Microsoft desktop toolset as a quick fix. That would select a different compiler and target environment, not a substitute PS3 PPU toolchain.

## 5. Set up Boost for Release builds

The Release configuration in `src/Minecraft.vcxproj` references this include path:

```text
$(SDKS)boost_1_36_0
```

This is Boost **1.36.0**, an old release. Use that version unless you have tested and intentionally updated the project for another version. A newer Boost release may contain API or compatibility changes.

### 5.1 Download Boost 1.36.0

The official Boost site has a [Boost 1.36.0 release page](https://www.boost.org/releases/1.36.0/). The [official Boost archives](https://archives.boost.io/release/) also list historical releases. Download the 1.36.0 source archive from the official Boost domain and extract it.

Boost 1.36.0 is from 2008. Its age is relevant: do not assume modern compilers or modern Boost versions will behave the same way with this legacy project.

### 5.2 Place the directory where the project expects it

For example, if you choose:

```text
D:\SDKs\boost_1_36_0\
```

then set `SDKS` to:

```text
D:\SDKs\
```

The project concatenates `$(SDKS)` and `boost_1_36_0`, so the parent path should end with a backslash. The resulting include path should point to the extracted Boost directory containing folders such as `boost\`.

You do not need to compile all Boost libraries merely to satisfy an include-directory reference, unless the source or linker later shows that compiled Boost libraries are also required. The checked-in project configuration specifically adds the Boost path to **Additional Include Directories** for Release.

## 6. Configure the environment variables

The project refers to three Windows environment variables:

| Variable | Set it to | Purpose |
|---|---|---|
| `SN_PS3_PATH` | The SNC toolchain root | Locates SNC headers and `libsn.a`. |
| `SCE_PS3_ROOT` | The PS3 SDK root | Locates PS3 PPU/common headers and SDK libraries. |
| `SDKS` | The parent folder containing `boost_1_36_0`, with a trailing `\` | Supplies the Boost include path for Release. |

The following paths are **examples only**. Replace them with the real folders on your computer:

```powershell
$env:SN_PS3_PATH = 'C:\Path\To\SNC'
$env:SCE_PS3_ROOT = 'C:\Path\To\PS3SDK'
$env:SDKS = 'D:\SDKs\'
```

### 6.1 Set variables for one build session (recommended for first test)

1. Open Developer PowerShell for the correct Visual Studio installation.
2. Change to the repository directory.
3. Paste the three assignments above, replacing each example path.
4. Check the values:

```powershell
$env:SN_PS3_PATH
$env:SCE_PS3_ROOT
$env:SDKS
```

5. Check that the expected files and folders exist. Adjust the paths to your installation rather than assuming the example values are correct.

These assignments only apply to that PowerShell process and programs launched from it. They do not permanently configure Windows, install the SDK, or register the SNC toolset.

### 6.2 Set variables permanently (optional)

If you build frequently, you can set user-level environment variables through Windows Settings or the **Environment Variables** dialog:

1. Open Start and search for **Edit environment variables for your account**.
2. Under **User variables**, choose **New** for each variable.
3. Enter the variable name exactly as shown in the table and the real directory path as its value.
4. For `SDKS`, include the trailing backslash, for example `D:\SDKs\`.
5. Close and reopen Developer PowerShell or Visual Studio so the new values are inherited.
6. Print each variable in PowerShell to verify it.

Avoid changing system-wide variables unless you understand the consequences and have permission to do so. Do not place credentials, tokens, private keys, or other secrets in environment variables that might be exposed to build logs.

## 7. Build in Visual Studio

1. Ensure the SDK, SNC integration, Boost folder, and environment variables are configured.
2. Open `KaguraClientSPRXV2.sln`.
3. If Visual Studio asks to retarget or upgrade the project, stop and review the proposed changes before accepting. Keep a clean backup or Git commit so you can revert an incompatible migration.
4. Find the **Solution Configurations** and **Solution Platforms** selectors, usually near the top of Visual Studio. Select one of the configurations actually defined by this solution:
   - `Debug` with platform `PS3`
   - `Release` with platform `PS3`
5. Do not select `x64` or `Win32`. Those are desktop targets and are not the PS3 configuration in this solution.
6. Select **Build → Build Solution**.
7. Open **View → Output** and choose the build output. Read the **first meaningful error** rather than starting with the final summary, because later errors may be consequences of an earlier missing header or library.

If the solution does not offer `PS3` as a platform, or says the `SNC` toolset is unavailable, fix the toolchain/Visual Studio integration first. Changing unrelated source files will not fix a missing compiler toolset.

## 8. Build from the command line

Command-line builds use MSBuild. Microsoft's [MSBuild overview](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild?view=visualstudio) and [command-line reference](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-command-line-reference?view=visualstudio) explain the switches used below.

1. Open Developer PowerShell for the Visual Studio installation with SNC integration.
2. Change directory to the folder containing `KaguraClientSPRXV2.sln`.
3. Set the environment variables as described in [Section 6](#6-configure-the-environment-variables).
4. Build Debug:

```powershell
msbuild .\KaguraClientSPRXV2.sln /m /t:Build /p:Configuration=Debug /p:Platform=PS3 /v:minimal
```

5. Build Release:

```powershell
msbuild .\KaguraClientSPRXV2.sln /m /t:Build /p:Configuration=Release /p:Platform=PS3 /v:minimal
```

The switches mean:

- `/m`: allow MSBuild to build projects in parallel where possible.
- `/t:Build`: request the Build target.
- `/p:Configuration=...`: select Debug or Release.
- `/p:Platform=PS3`: select the PS3 platform defined by the solution.
- `/v:minimal`: reduce routine output while retaining errors and important messages.

To save a log for troubleshooting, add a file logger, for example:

```powershell
msbuild .\KaguraClientSPRXV2.sln /t:Build /p:Configuration=Debug /p:Platform=PS3 /v:normal /flp:LogFile=build-debug.log
```

If `msbuild` is not recognised, use the matching Developer PowerShell or locate `MSBuild.exe` inside the Visual Studio installation. Do not run the command from an unrelated shell that does not have the intended environment configured.

## 9. Find the output and understand post-build steps

The project sets the output directories to:

```text
bin\Debug-PS3\
bin\Release-PS3\
```

Intermediate files are written under `bin-int\`, in a configuration/platform/project-specific subdirectory. The precise final filename depends on the project settings and toolchain.

The project also contains conditional post-build commands:

- Debug attempts to run `InjectSPRX.exe` if it exists in the output directory.
- Release attempts to run `loadSprx.exe` if it exists in the output directory.

These utilities are **not included or installed by this guide**. If compilation and linking succeed but a post-build step fails, inspect the complete build log and determine whether that optional utility is expected in your particular setup. Do not download similarly named executables from unknown sources.

A successful build means only that the toolchain completed the requested build steps. It does not guarantee compatibility with a particular console, firmware, or runtime environment. Do not load untrusted binaries onto a device.

## 10. Linux and macOS

There is no configured native Linux or macOS build system in this repository. The checked-in project is a Visual Studio/MSBuild C++ project configured for the Windows SNC PS3 toolset and the PS3 SDK paths described above. A normal Linux GCC/Clang or macOS Xcode/Clang installation cannot build it as configured.

Practical options are:

- Edit the source on Linux or macOS, then build on a Windows machine with the required licensed SDK and SNC integration.
- Use a Windows virtual machine only if the relevant software licences permit it and the SNC integration supports that environment.

There is no supplied CMake or Makefile build. Creating a portable build would be a separate engineering task requiring a compatible PS3 PPU toolchain and deliberate build-system maintenance.

## 11. Troubleshooting

### `SNC` platform toolset is missing, or MSB8020 appears

The SNC integration is not installed, is not registered with this Visual Studio instance, or is incompatible with that Visual Studio version. Verify the exact Visual Studio instance and follow the toolchain vendor's installation instructions. Installing standard MSVC alone is not sufficient.

### `msbuild` is not recognised

Use Developer PowerShell for Visual Studio, or call the correct `MSBuild.exe` by full path. Check that the C++ workload and MSBuild are installed. See Microsoft's [MSBuild documentation](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild?view=visualstudio).

### Headers under `SN_PS3_PATH` cannot be found

Print `$env:SN_PS3_PATH` and check that the installed toolchain has the expected `ppu\include\sn` directory. The variable must point to the root expected by this project, not directly to the `include` directory.

### PS3 headers or libraries under `SCE_PS3_ROOT` cannot be found

Check the value of `$env:SCE_PS3_ROOT` and confirm that the expected `target\ppu\include`, `target\common\include`, and `target\ppu\lib` paths exist in your authorised SDK installation.

### Boost headers cannot be found in Release

Check that `SDKS` points to the parent directory and ends in a backslash. For example, `D:\SDKs\` should make `$(SDKS)boost_1_36_0` resolve to `D:\SDKs\boost_1_36_0`. Confirm that the extracted directory contains the `boost` header folder.

### Linker errors for PS3 libraries

Check the first linker error and verify the referenced library exists under the SDK/toolchain root. The project expects libraries including `libc.a`, `libsn.a`, `libm.a`, `libio_stub.a`, `liblv2_stub.a`, `libc_stub.a`, `libsysutil_stub.a`, `libsyscall.a`, and `libsha256.a`. Do not substitute similarly named desktop libraries.

### Debug builds but Release does not

Release adds the Boost 1.36.0 include directory, so a missing Boost installation or incorrect `SDKS` path is a likely cause. Other configuration-specific issues may also exist; compare the first error in each build log.

### Build succeeds but `InjectSPRX.exe` or `loadSprx.exe` fails

These are conditional post-build utilities. Check whether the executable exists in the target output directory and consult its trusted documentation if it is part of your authorised toolchain. The repository does not provide enough information to guarantee what those external utilities do or which version is required.

### The solution asks to upgrade or retarget

The solution uses an older Visual Studio project format. Back up the repository before accepting project migrations. If the SNC integration requires a specific Visual Studio generation, use a compatible installation rather than assuming the newest version will work.

## 12. Security, licensing, and project boundaries

- Obtain proprietary SDK/compiler packages only through a source you are authorised to use, and follow their licence terms.
- Do not commit SDK files, SDK licence material, private keys, credentials, console-specific secrets, or proprietary libraries to this repository.
- Treat unknown binaries and unofficial SDK archives as untrusted.
- Keep generated outputs and local IDE caches out of commits unless a maintainer has a specific reason to version them.
- If testing a resulting binary, use only devices and environments you own or are authorised to use.
- This guide documents the project configuration; it does not promise that the current source will compile without fixes on every SDK/toolchain version.

## 13. Reference links

The links below are official vendor/project resources wherever publicly available. The PS3 SDK and SNC toolchain are proprietary; public documentation does not imply that their installers are publicly available.

### Microsoft

- [Visual Studio downloads](https://visualstudio.microsoft.com/downloads/) - official installer entry point.
- [Older Visual Studio downloads](https://visualstudio.microsoft.com/vs/older-downloads/) - older releases; availability may require a subscription.
- [Install Visual Studio](https://learn.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=visualstudio) - installation and workload instructions.
- [C++ Build Tools workload/components](https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=vs-2022) - explains the C++ workload and MSBuild components.
- [MSBuild overview](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild?view=visualstudio) - MSBuild concepts and usage.
- [MSBuild command-line reference](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-command-line-reference?view=visualstudio) - command-line switches and logging.

### PlayStation / SNC

- [PlayStation Partners](https://partners.playstation.net/) - official starting point for authorised PlayStation developer resources. Legacy PS3 SDK access may be restricted and is not guaranteed.
- The installation manuals and support materials supplied with your authorised PS3 SDK/SNC package are the source of truth for its version-specific installation paths and compatibility. There is no public download link provided here for the proprietary SDK/compiler.

### Boost

- [Boost 1.36.0 release page](https://www.boost.org/releases/1.36.0/) - official release information.
- [Boost official release archives](https://archives.boost.io/release/) - official archive index for historical Boost releases.

### GitHub and Git

- [Kagura Client V2 repository](https://github.com/SSMG64/KaguraClientV2) - source repository.
- [Git documentation: git clone](https://git-scm.com/docs/git-clone) - cloning the repository.

---

If you report a build issue, include the selected configuration (`Debug|PS3` or `Release|PS3`), Visual Studio version, SNC/SDK versions if known, the values of the three path variables with any sensitive information removed, and the **first relevant error** from the build log. Never post credentials, private keys, or proprietary SDK files in an issue.
