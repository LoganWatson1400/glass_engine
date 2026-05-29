#include "types/UUID.hh"
#include <catch2/catch_all.hpp>

TEST_CASE("uuid", "[uuid]") {
	SECTION("uuid generates") {
		core::UUID uuid1 = core::UUID::generate();

		REQUIRE(uuid1.low != 0);
		REQUIRE(uuid1.high != 0);
	}

	SECTION("uuid from string") {
		std::string uuid_string = "12345678123456781234567812345678";
		core::UUID uuid1 = core::UUID::from_string(uuid_string);
		REQUIRE(uuid1.to_string() == uuid_string);
	}

	SECTION("uuid comparators") {
		std::string uuid_string1 = "12345678123456781234567812345678";
		std::string uuid_string2 = uuid_string1;
		std::reverse(uuid_string2.begin(), uuid_string2.end());
		
		core::UUID uuid1 = core::UUID::from_string(uuid_string1);
		core::UUID uuid2 = core::UUID::from_string(uuid_string2);

		REQUIRE(uuid1 == uuid1);
		REQUIRE(uuid1 != uuid2);
	}
}