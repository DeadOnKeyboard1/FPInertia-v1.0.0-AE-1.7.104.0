# Changelog

## Skyrim 1.7.104.0 Compatibility Port

- Added compatibility support for Skyrim Special Edition / Anniversary Edition runtime `1.7.104.0` (SKSE `2.3.1`).
- Upgraded build configuration to CommonLibSSE-NG (v8.0.0, commit `1504349dddfc622d4d25704bba19e2ade669dc5a`).
- Statically verified memory hooks in runtime `1.7.104.0`:
  - `MainUpdateHook`: Address Library ID `36564` + offset `0xC26`.
  - `UpdateFirstPersonHook`: Address Library ID `40522` + offset `0xD7`.
- Added portable in-repo compatibility source `compat/src/compat_stl.cpp` to resolve MSVC STL functions and fmt v12 allocator.
- Added compiler definitions to silence C++17 deprecation warnings in `SKSEMenuFramework`.
- Kept upstream plugin source files in `src/` 100% untouched.
- Added comprehensive third-party legal notices in `THIRD_PARTY_NOTICES.md`.
