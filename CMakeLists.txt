cmake_minimum_required(VERSION 3.16)
project(tetris)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Use vendored libs
set(SDLTTF_VENDORED OFF)

# This assumes the SDL source is available in vendor/SDL
add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

# This assumes the SDL_ttf source is available in vendor/SDL_ttf
add_subdirectory(vendor/SDL_ttf EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(tetris src/main.c src/grid.c src/ui.c)

# Link to the actual SDL3 library.
target_link_libraries(tetris PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)
