cmake_minimum_required(VERSION 3.28)
project(
    glass_engine
    DESCRIPTION "GlassDragons Game engine written in C++"
    VERSION 1.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 3 REQUIRED)
find_package(SDL2   REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW   REQUIRED)
find_package(glm    REQUIRED)

add_library(glass_engine_lib
    src/engine/Engine.cpp
    src/world/GameObject.cpp
    src/world/SceneTree.cpp
    src/rendering/Renderer.cpp
    src/rendering/Camera.cpp
    src/rendering/Mesh.cpp
    src/rendering/Shader.cpp
    src/platform/Window.cpp
)
target_include_directories(glass_engine_lib PUBLIC src)
target_link_libraries(glass_engine_lib PUBLIC
    SDL2::SDL2
    OpenGL::GL
    GLEW::GLEW
    glm::glm
)

add_executable(glass_engine src/main.cpp)
target_link_libraries(glass_engine PRIVATE glass_engine_lib)

add_executable(tests
    tests/engine_tests/engine_tests.cpp
    tests/main_tests/test_main.cpp
    tests/world_tests/gameobject_tests.cpp
    tests/world_tests/scene_tests.cpp
    tests/rendering_tests/camera_tests.cpp
    tests/rendering_tests/renderer_tests.cpp
    tests/rendering_tests/mesh_tests.cpp
    tests/platform_tests/window_tests.cpp
)
target_link_libraries(tests PRIVATE glass_engine_lib Catch2::Catch2WithMain)

enable_testing()
add_test(NAME all_tests COMMAND tests)