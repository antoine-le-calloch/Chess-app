cmake_minimum_required(VERSION 3.20)
project(IA_chess C)

set(CMAKE_C_STANDARD 99)

# --- SOURCES ---
file(GLOB_RECURSE SOURCES "source/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
