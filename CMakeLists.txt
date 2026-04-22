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
# add_subdirectory(external/catch2)

add_library(glass_engine_lib
    src/engine/Engine.cpp
    src/world/GameObject.cpp
    src/world/SceneTree.cpp
    src/rendering/Renderer.cpp
    src/rendering/Camera.cpp
    src/platform/Window.cpp
)
target_include_directories(glass_engine_lib PUBLIC src)

add_executable(glass_engine src/main.cpp)
target_link_libraries(glass_engine PRIVATE glass_engine_lib)

add_executable(tests
    tests/engine_tests/engine_tests.cpp
    tests/main_tests/test_main.cpp
    tests/world_tests/gameobject_tests.cpp
    tests/world_tests/scene_tests.cpp
    tests/rendering_tests/camera_tests.cpp
    tests/rendering_tests/renderer_tests.cpp
    tests/platform_tests/window_tests.cpp
)
target_link_libraries(tests PRIVATE glass_engine_lib Catch2::Catch2WithMain)

enable_testing()
add_test(NAME all_tests COMMAND tests)