cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

# CPM
file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

set(LIBS)

## Dependencies

# SDL
CPMAddPackage("gh:libsdl-org/SDL#4c70aa3")
list(APPEND LIBS SDL3::SDL3)

# SDL_image
set(SDLIMAGE_AVIF OFF CACHE BOOL "" FORCE) # Requires Perl and Nasm for libaom (AVIF image format)
CPMAddPackage("gh:libsdl-org/SDL_image#bcc97c0")
list(APPEND LIBS SDL3_image::SDL3_image)

# flecs
CPMAddPackage("gh:SanderMertens/flecs#befc214")
list(APPEND LIBS flecs::flecs)

# SQLite
CPMAddPackage("gh:SRombauts/SQLiteCpp#643b153")
list(APPEND LIBS SQLiteCpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})