# -- Minimum required version
cmake_minimum_required(VERSION 3.10)

# -- Project name
project(freemodbus)

# -- Various includes
include (CMakePackageConfigHelpers)
include (GNUInstallDirs)

# -- Set c99 standard default
set(CMAKE_C_STANDARD 11)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
if (NOT (${CMAKE_INSTALL_PREFIX} STREQUAL "/usr" ) )
    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
endif()

# -- include the library part
include (modbus/CMakeLists.txt)

include (demo/CMakeLists.txt)



