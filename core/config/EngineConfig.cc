#include "EngineConfig.hh"
#include "ConfigLoader.hh"

namespace core {

void EngineConfig::load() {
    ConfigLoader::load_file("engine_config.cfg");
}

int EngineConfig::window_width() {
    return ConfigLoader::get_int("window.width");
}

int EngineConfig::window_height() {
    return ConfigLoader::get_int("window.height");
}

bool EngineConfig::vsync() {
    return ConfigLoader::get_bool("window.vsync");
}

std::string EngineConfig::renderer_backend() {
    return ConfigLoader::get("renderer");
}

std::string EngineConfig::title() {
    return ConfigLoader::get("window.title");
}

} // namespace core