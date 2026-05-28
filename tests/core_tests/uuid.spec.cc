#include "core/types/UUID.hh"
#include <catch2/catch_all.hpp>

TEST_CASE("uuid", "[uuid]") {
	SECTION("uuid generates") {
		core::UUID uuid1 = core::UUID::generate();

		REQUIRE(uuid1.high != 0 || uuid1.low != 0);
	}

	SECTION("uuid from string") {
		std::string uuid_string = "12345678-1234-5678-1234-567812345678";
		core::UUID uuid1 = core::UUID::from_string(uuid_string);
		REQUIRE(uuid1.to_string() == uuid_string);
	}

	SECTION("uuid comparators") {
		std::string uuid_string1 = "12345678-1234-5678-1234-567812345678";
		std::string uuid_string2 = "87654321-4321-8765-4321-876543218765";
		core::UUID uuid1 = core::UUID::from_string(uuid_string1);
		core::UUID uuid2 = core::UUID::from_string(uuid_string2);

		REQUIRE(uuid1 == uuid1);
		REQUIRE(uuid1 != uuid2);
	}
}