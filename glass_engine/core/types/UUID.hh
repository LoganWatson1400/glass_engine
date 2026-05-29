#ifndef GLASS_ENGINE_UUID_HH
#define GLASS_ENGINE_UUID_HH

#include <cstdint>
#include <string>

namespace core {

/**
 * UUID (128-bit identifier)
 * Used for uniquely identifying engine objects, resources,
 * scene nodes, etc.
 */
struct UUID {
	uint64_t high = 0;
	uint64_t low = 0;

	UUID() = default;
	UUID(uint64_t h, uint64_t l) : high(h), low(l) {}

	/// Equality comparison between two UUIDs
	bool operator==(const UUID &other) const {
		return high == other.high && low == other.low;
	}

	/// Inequality comparison
	bool operator!=(const UUID &other) const { return !(*this == other); }

	/// Converts UUID to 32-char hex string
	std::string to_string() const;

	/// Parses UUID from 32-char hex string
	static UUID from_string(const std::string &str);

	/// Generates a new random UUID
	static UUID generate();
};

} // namespace core

#endif // GLASS_ENGINE_UUID_HH