list(APPEND CMAKE_PREFIX_PATH "/usr/lib/cmake/Catch2")
find_package(Catch2 3 REQUIRED)


add_executable(tests
    tests/engine_tests/test_main.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)