#include "ConfigLoader.hh"
#include <fstream>

namespace core {

std::unordered_map<std::string, std::string> &ConfigLoader::data() {
	static std::unordered_map<std::string, std::string> map;
	return map;
}

bool ConfigLoader::load_file(const std::string &path) {
	std::ifstream file(path);
	if (!file.is_open())
		return false;

	std::string line;

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t eq = line.find('=');
		if (eq == std::string::npos)
			continue;

		std::string key = line.substr(0, eq);
		std::string value = line.substr(eq + 1);

		data()[key] = value;
	}

	return true;
}

std::string ConfigLoader::get(const std::string &key) { return data()[key]; }

int ConfigLoader::get_int(const std::string &key) {
	return std::stoi(get(key));
}

bool ConfigLoader::get_bool(const std::string &key) {
	std::string v = get(key);
	return v == "true" || v == "1";
}

} // namespace core