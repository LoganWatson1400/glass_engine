cmake_minimum_required(VERSION 3.28)
project(
    glass_engine
    DESCRIPTION "GlassDragons Game engine written in C++"
    VERSION 1.0
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2   REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW   REQUIRED)
find_package(glm    REQUIRED)

# Catch2
add_subdirectory(external/catch2)

# ImGui
add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_sdl2.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
    external/imgui
    external/imgui/backends
)
target_link_libraries(imgui PUBLIC SDL2::SDL2 OpenGL::GL)

# Engine library
file(GLOB_RECURSE ENGINE_SOURCES
    src/engine/*.cpp
    src/world/*.cpp
    src/rendering/*.cpp
    src/platform/*.cpp
)
add_library(glass_engine_lib ${ENGINE_SOURCES})
target_include_directories(glass_engine_lib PUBLIC src)
target_link_libraries(glass_engine_lib PUBLIC
    SDL2::SDL2
    OpenGL::GL
    GLEW::GLEW
    glm::glm
)

# Game
add_executable(glass_engine src/main.cpp)
target_link_libraries(glass_engine PRIVATE glass_engine_lib)

# Editor
# file(GLOB_RECURSE EDITOR_SOURCES editor/*.cpp)
# add_executable(glass_editor ${EDITOR_SOURCES})
# target_include_directories(glass_editor PRIVATE editor)
# target_link_libraries(glass_editor PRIVATE glass_engine_lib imgui)


# Tests
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
add_executable(tests ${TEST_SOURCES})
target_include_directories(tests PRIVATE editor)
target_link_libraries(tests PRIVATE glass_engine_lib Catch2::Catch2WithMain)

enable_testing()
add_test(NAME all_tests COMMAND tests)