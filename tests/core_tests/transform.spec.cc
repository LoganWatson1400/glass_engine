#include <catch2/catch_test_macros.hpp>

#include "core/math/Transform.hh"

#include <glm/gtc/epsilon.hpp>
#include <glm/gtx/string_cast.hpp>
#include <catch_amalgamated.hpp>

TEST_CASE("Transform toMatrix", "[transform]") {
	SECTION("identity transform") {
		Transform t;

		glm::mat4 m = t.toMatrix();

		glm::mat4 identity(1.0f);

		REQUIRE(m == identity);
	}

	SECTION("translation") {
		Transform t;
		t.position = {5.0f, 2.0f, -3.0f};

		glm::mat4 m = t.toMatrix();

		REQUIRE(m[3][0] == Catch::Approx(5.0f));
		REQUIRE(m[3][1] == Catch::Approx(2.0f));
		REQUIRE(m[3][2] == Catch::Approx(-3.0f));
	}

	SECTION("scale") {
		Transform t;
		t.scale = {2.0f, 3.0f, 4.0f};

		glm::mat4 m = t.toMatrix();

		REQUIRE(m[0][0] == Catch::Approx(2.0f));
		REQUIRE(m[1][1] == Catch::Approx(3.0f));
		REQUIRE(m[2][2] == Catch::Approx(4.0f));
	}

	SECTION("rotation around Y") {
		Transform t;
		t.rotation.y = 90.0f;

		glm::mat4 m = t.toMatrix();

		glm::vec4 forward = m * glm::vec4(0, 0, 1, 0);

		REQUIRE(forward.x == Catch::Approx(1.0f).margin(0.001f));
		REQUIRE(forward.z == Catch::Approx(0.0f).margin(0.001f));
	}

	SECTION("combined transform") {
		Transform t;

		t.position = {1.0f, 2.0f, 3.0f};
		t.rotation = {0.0f, 90.0f, 0.0f};
		t.scale = {2.0f, 2.0f, 2.0f};

		glm::mat4 m = t.toMatrix();

		REQUIRE(m[3][0] == Catch::Approx(1.0f));
		REQUIRE(m[3][1] == Catch::Approx(2.0f));
		REQUIRE(m[3][2] == Catch::Approx(3.0f));
	}
}