#ifndef GLASS_ENGINE_CONFIGPATH_HH
#define GLASS_ENGINE_CONFIGPATH_HH
#include "config/ConfigLoader.hh"

inline void load_test_configs() {
    core::ConfigLoader::load_file(ENGINE_CONFIG_PATH);
    core::ConfigLoader::load_file(PROJECT_CONFIG_PATH);
}

#endif // GLASS_ENGINE_CONFIGPATH_HH