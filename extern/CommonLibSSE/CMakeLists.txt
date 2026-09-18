cmake_minimum_required(VERSION 3.21)

project(CommonLibSSE LANGUAGES CXX)

if(DEFINED COMMONLIB_ROOT)
    set(COMPAT_COMMONLIB "${COMMONLIB_ROOT}")
elseif(DEFINED ENV{COMMONLIB_ROOT})
    set(COMPAT_COMMONLIB "$ENV{COMMONLIB_ROOT}")
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/CommonLibSSE.lib")
    set(COMPAT_COMMONLIB "${CMAKE_CURRENT_SOURCE_DIR}")
elseif(EXISTS "${CMAKE_SOURCE_DIR}/../_toolchain/skyrim_1_7_104_compat/CommonLibSSE")
    set(COMPAT_COMMONLIB "${CMAKE_SOURCE_DIR}/../_toolchain/skyrim_1_7_104_compat/CommonLibSSE")
endif()

if(COMPAT_COMMONLIB)
    get_filename_component(COMPAT_COMMONLIB "${COMPAT_COMMONLIB}" ABSOLUTE)
endif()

if(NOT EXISTS "${COMPAT_COMMONLIB}/lib/CommonLibSSE.lib")
    message(FATAL_ERROR "Could not find CommonLibSSE at '${COMPAT_COMMONLIB}'. Please specify -DCOMMONLIB_ROOT=<path> or set the COMMONLIB_ROOT environment variable.")
endif()

set(COMPAT_SRC "${CMAKE_SOURCE_DIR}/compat/src/compat_stl.cpp")
if(NOT EXISTS "${COMPAT_SRC}")
    set(COMPAT_SRC "${CMAKE_SOURCE_DIR}/../_toolchain/skyrim_1_7_104_compat/src/compat_stl.cpp")
endif()
get_filename_component(COMPAT_SRC "${COMPAT_SRC}" ABSOLUTE)

find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(directxtk CONFIG REQUIRED)

add_library(CommonLibSSE STATIC IMPORTED GLOBAL)
set_target_properties(CommonLibSSE PROPERTIES
    IMPORTED_LOCATION "${COMPAT_COMMONLIB}/lib/CommonLibSSE.lib"
    IMPORTED_LOCATION_RELEASE "${COMPAT_COMMONLIB}/lib/CommonLibSSE.lib"
    IMPORTED_LOCATION_DEBUG "${COMPAT_COMMONLIB}/lib/CommonLibSSE.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${COMPAT_COMMONLIB}/include"
    INTERFACE_COMPILE_FEATURES "cxx_std_23"
    INTERFACE_COMPILE_DEFINITIONS "WINVER=0x0601;_WIN32_WINNT=0x0601;ENABLE_SKYRIM_SE=1;ENABLE_SKYRIM_AE=1;HAS_SKYRIM_MULTI_TARGETING=1;SKSE_SUPPORT_PATCH_SAFETY=1;_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"
    INTERFACE_LINK_LIBRARIES "spdlog::spdlog;fmt::fmt;Microsoft::DirectXTK;advapi32.lib;bcrypt.lib;D3D11.lib;d3dcompiler.lib;dbghelp.lib;DXGI.lib;ole32.lib;version.lib"
    INTERFACE_SOURCES "${COMPAT_SRC}"
)

add_library(CommonLibSSE::CommonLibSSE ALIAS CommonLibSSE)
