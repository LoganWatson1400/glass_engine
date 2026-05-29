#ifndef GLASS_ENGINE_ENGINECONFIG_HH
#define GLASS_ENGINE_ENGINECONFIG_HH

#include <string>

namespace core {

/**
 * Engine-level configuration
 *
 * Controls renderer, window system, debug options, etc.
 */
class EngineConfig {
  public:
	/// @brief Load engine config
	static void load();

	/// @return Window width in px
	static int window_width();

	/// @return Window height in px
	static int window_height();

	/// @return Bool for vsync status 
	static bool vsync();

	/// @return name of renderer name (opengl, vulkan)
	static std::string renderer_backend();

	/// @return Window title string
	static std::string title();
};

} // namespace core
#endif // GLASS_ENGINE_ENGINECONFIG_HH