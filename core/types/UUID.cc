#include "UUID.hh"
#include <iomanip>
#include <random>
#include <sstream>

namespace core {

static std::random_device rd;
static std::mt19937_64 gen(rd());
static std::uniform_int_distribution<uint64_t> dist;

UUID UUID::generate() { return UUID(dist(gen), dist(gen)); }

std::string UUID::to_string() const {
	std::stringstream ss;

	ss << std::hex << std::setfill('0') << std::setw(16) << high
	   << std::setw(16) << low;

	return ss.str();
}

UUID UUID::from_string(const std::string &str) {
	if (str.size() != 32)
		return {};

	UUID id;

	std::stringstream high_ss(str.substr(0, 16));
	std::stringstream low_ss(str.substr(16, 16));

	high_ss >> std::hex >> id.high;
	low_ss >> std::hex >> id.low;

	return id;
}

} // namespace core