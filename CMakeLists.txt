cmake_minimum_required(VERSION 3.18)
project(pitara)

include(FetchContent)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set_property(GLOBAL PROPERTY C_STANDARD 11)

if (CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "armv7l")
  set(PLATFORM DRM)
else()
  set(PLATFORM Desktop)
endif()

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.0
)

FetchContent_MakeAvailable(
  raylib
)

add_executable(pitara src/main.c)

target_link_libraries(
  pitara
  raylib
)

add_custom_target(run
    COMMAND pitara
    DEPENDS pitara
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
