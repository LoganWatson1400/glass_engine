#include "platform/Window.hh"
#include "config/ConfigLoader.hh"
#include "helpers/config_path.hh"
#include <catch2/catch_all.hpp>

struct WindowFixture {
	WindowFixture() { load_test_configs(); }
};

TEST_CASE_METHOD(WindowFixture, "Window", "[window]") {
	SECTION("Has default dimensions") {
		Window window;
		REQUIRE(window.width == 800);
		REQUIRE(window.height == 600);
	}

	SECTION("Is closed before init") {
		Window window;
		REQUIRE(window.isOpen() == false);
	}

	// Integration test: requires a display. Returns false gracefully in
	// headless env.
	SECTION("Can init") {
		Window window;
		window.init();
		SUCCEED();
	}

	SECTION("Is closed after close()") {
		Window window;
		window.init();
		window.close();
		REQUIRE(window.isOpen() == false);
	}
}