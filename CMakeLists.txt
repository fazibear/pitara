cmake_minimum_required(VERSION 3.18)
project(pitara)

include(FetchContent)

set(BIN_NAME pitara)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

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

FetchContent_Declare(
  rtmidi
  GIT_REPOSITORY https://github.com/thestk/rtmidi.git
  GIT_TAG        6.0.0
)

FetchContent_MakeAvailable(
  rtmidi raylib
)

FILE(GLOB SOURCE_FILES src/*.c)
add_executable(pitara ${SOURCE_FILES})

target_link_libraries(
  ${BIN_NAME}
  raylib
  rtmidi
)

add_custom_target(run
    COMMAND ${BIN_NAME}
    DEPENDS ${BIN_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
