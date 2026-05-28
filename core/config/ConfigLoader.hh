#ifndef GLASS_ENGINE_CONFIGLOADER_HH
#define GLASS_ENGINE_CONFIGLOADER_HH

#include <string>
#include <unordered_map>

namespace core {

class ConfigLoader {
  public:
	/// @brief Parse a config file from a path
	/// @param path 
	/// @return success
	static bool load_file(const std::string &path);

	/// @brief Retrive a value by key as a string
	/// @param key 
	/// @return value for the given key
	static std::string get(const std::string &key);

	/// @brief Retrive a value by key as an int 
	/// @param key 
	/// @return value for the given key
	static int get_int(const std::string &key);
    
    /// @brief Retrive a value by key as a bool
	/// @param key 
	/// @return value for the given key
	static bool get_bool(const std::string &key);

  private:
	static std::unordered_map<std::string, std::string> &data();
};

} // namespace core

#endif // GLASS_ENGINE_CONFIGLOADER_HH