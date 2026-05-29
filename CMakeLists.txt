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

# Engine library (core + framework)
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/glass_engine/*.cc
)
add_library(glass_engine_lib STATIC ${ENGINE_SOURCES})
target_include_directories(glass_engine_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/glass_engine
    ${CMAKE_SOURCE_DIR}/glass_engine/core
    ${CMAKE_SOURCE_DIR}/glass_engine/framework
)
target_link_libraries(glass_engine_lib PUBLIC
    SDL2::SDL2
    OpenGL::GL
    GLEW::GLEW
    glm::glm
)

# Game
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/game_project/game/*.cc
)
add_executable(glass_engine_game
    ${CMAKE_SOURCE_DIR}/game_project/main.cc
    ${GAME_SOURCES}
)
target_link_libraries(glass_engine_game PRIVATE glass_engine_lib)

# Editor
# file(GLOB_RECURSE EDITOR_SOURCES ${CMAKE_SOURCE_DIR}/editor/*.cc)
# add_executable(glass_editor ${EDITOR_SOURCES})
# target_link_libraries(glass_editor PRIVATE glass_engine_lib imgui)

# Tests
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/tests/*.cc
)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE glass_engine_lib Catch2::Catch2WithMain)

enable_testing()
add_test(NAME all_tests COMMAND tests)
target_compile_definitions(tests PRIVATE
    ENGINE_CONFIG_PATH="${CMAKE_SOURCE_DIR}/game_project/config/engine_config.cfg"
    PROJECT_CONFIG_PATH="${CMAKE_SOURCE_DIR}/game_project/config/project_config.cfg"
)