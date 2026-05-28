#include "ProjectConfig.hh"
#include "ConfigLoader.hh"
#include <sstream>

namespace core {

void ProjectSettings::load() { 
    ConfigLoader::load_file("project_config.cfg"); 
}

std::string ProjectSettings::start_scene() {
	return ConfigLoader::get("start_scene");
}

std::array<float, 3> ProjectSettings::gravity() {
	std::string g = ConfigLoader::get("physics.gravity");

	std::array<float, 3> result{};
	std::istringstream ss(g);
	std::string token;
	int i = 0;

	while (std::getline(ss, token, ',') && i < 3) {
		result[i++] = std::stof(token);
	}

	return result;
}

} // namespace core