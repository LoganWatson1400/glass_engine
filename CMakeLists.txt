cmake_minimum_required(VERSION 3.28)
project(glass_engine)

list(APPEND CMAKE_PREFIX_PATH "/usr/lib/cmake/Catch2")
find_package(Catch2 REQUIRED)

add_executable(tests
    tests/engine_tests/engine_tests.cpp
    tests/main_tests/test_main.cpp
    tests/world_tests/gameobject_tests.cpp

    src/engine/Engine.cpp
    src/world/GameObject.cpp
    src/world/SceneTree.cpp
    src/rendering/Renderer.cpp
    src/rendering/Camera.cpp
    src/platform/Window.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src)

enable_testing()
add_test(NAME all_tests COMMAND tests)