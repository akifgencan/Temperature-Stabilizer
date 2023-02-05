cmake_minimum_required(VERSION 3.0.0)

include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)


set(This tempStabilizer)

project(${This})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


include(CTest)
enable_testing()

#add_subdirectory(googletest)
include(GoogleTest)

set(HEADERS
       main.hpp
)

set(SOURCES
       main.cpp
)

add_library(${This} STATIC ${Sources} ${HEADERS})

#add_executable(temperature-stabilizer main.cpp)

add_subdirectory(test)

set_target_properties(${This} PROPERTIES LINKER_LANGUAGE CXX)
#set(CPACK_PROJECT_NAME ${Temperature-Stabilizer})
#set(CPACK_PROJECT_VERSION ${0.1.0})
#include(CPack)
