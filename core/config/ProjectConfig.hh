#ifndef GLASS_ENGINE_PROJECTCONFIG_HH
#define GLASS_ENGINE_PROJECTCONFIG_HH

#include <array>
#include <string>

namespace core {

/**
 * Game/project-specific settings
 * Examples:
 * - start scene
 * - physics settings
 * - input bindings
 */
class ProjectSettings {
  public:
	/// @brief Load project settings from the disk
	static void load();

	/// @return Path to start scene
	static std::string start_scene();

	/// @return Gravity vector
	static std::array<float, 3> gravity();
};

} // namespace core
#endif // GLASS_ENGINE_PROJECTCONFIG_HH