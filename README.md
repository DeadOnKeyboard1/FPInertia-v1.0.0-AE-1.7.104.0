# FPInertia - Skyrim 1.7.104.0 Compatibility Port

Adds spring-interpolated first person inertia to Skyrim Special Edition.

This repository contains the source code and build system for the **Skyrim 1.7.104.0 compatibility port** of **FPInertia**.

> **Note & Credits:**
> The original mod was created by **[DCC Studios](https://github.com/DCCStudios)**.
> Original upstream repository: [https://github.com/DCCStudios/SkyrimSE-FPInertia](https://github.com/DCCStudios/SkyrimSE-FPInertia)
> Original mod page: [Nexus Mods](https://www.nexusmods.com/skyrimspecialedition/mods/141018)
> I did not create the original mod; this project only provides the compatibility port and build updates for Skyrim 1.7.104.0.

---

## Requirements

### Runtime
- **The Elder Scrolls V: Skyrim Special Edition / Anniversary Edition** (Runtime `1.7.104.0`)
- **[SKSE64](https://skse.silverlock.org/)** (Version `2.3.1` or compatible)
- **[Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)** (matching 1.7.104.0 database)
- The original mod remains recommended for full base installation.

---

## Compatibility Details

- **Target Runtime:** Skyrim SE / AE 1.7.104.0
- **SKSE Target:** SKSE 2.3.1
- **CommonLib:** [CommonLibSSE-NG](https://github.com/alandtse/CommonLibVR) (branch `ng`, commit `1504349dddfc622d4d25704bba19e2ade669dc5a`, v8.0.0)
- **Hooks Verified for 1.7.104.0:**
  - `MainUpdateHook`: Address Library ID `36564` (RVA `0x658870`) + offset `0xC26` = `0x659496` (verified 5-byte call instruction).
  - `UpdateFirstPersonHook`: Address Library ID `40522` (RVA `0x74C080`) + offset `0xD7` = `0x74C157` (verified 5-byte call instruction).
- **Compatibility Layer:**
  - Portable MSVC STL runtime helper `compat/src/compat_stl.cpp` provides missing symbols (`__std_replace_copy_2`, `__std_find_first_not_of_trivial_pos_1`, `__std_regex_transform_primary_char`) and `fmt::v12::detail::allocate`.
  - Upstream source files in `src/` remain completely unchanged.

---

## Building from Source

### Prerequisites
- **Visual Studio 2022** (MSVC Toolset v143+ with "Desktop development with C++" workload)
- **CMake 3.21+** (added to PATH)
- **vcpkg** (with `VCPKG_ROOT` environment variable set)
- **CommonLibSSE-NG** (prebuilt headers/library; specify via `-DCOMMONLIB_ROOT=<path>` or set `COMMONLIB_ROOT` environment variable)

### Build Steps

1. Configure with CMake:
   ```cmd
   cmake --preset release -DCOMMONLIB_ROOT="<path_to_commonlib>"
   ```
   *(If `COMMONLIB_ROOT` environment variable is already set, `-DCOMMONLIB_ROOT` can be omitted).*

2. Build the project:
   ```cmd
   cmake --build build/release --config Release
   ```

3. The compiled plugin (`FPInertia.dll`, `FPInertia.pdb`, `FPInertia.ini`) will be placed into:
   ```
   Compile/SKSE/Plugins/
   ```

---

## Configuration

Edit `Data/SKSE/Plugins/FPInertia.ini` to customize inertia settings and keybindings.

---

## Licenses

- **Project License:** [GNU General Public License v3.0 or later (GPL-3.0-or-later)](./LICENSE) with [Modding & Linking Exceptions](./EXCEPTIONS.md)
- **Original Mod Code:** [MIT License](./LICENSE-ORIGINAL-FPInertia.txt) (c) 2025 DCC Studios
- **Third-Party Notices:** See [THIRD_PARTY_NOTICES.md](./THIRD_PARTY_NOTICES.md) for licenses of CommonLibSSE-NG, DirectXTK, fmt, nlohmann-json, rapidcsv, simpleini, and spdlog.
