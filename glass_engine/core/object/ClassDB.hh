#ifndef GLASS_ENGINE_CLASSDB_HH
#define GLASS_ENGINE_CLASSDB_HH

#include <functional>
#include <string>
#include <unordered_map>

#include "Object.hh"

class ClassDB {
  public:
	using CreateFunc = Object *(*)();

	struct ClassInfo {
		CreateFunc creator = nullptr;
		std::string parent;
	};

    /**
     * Registers a class with optional parent info.
     */
	static void register_class(const std::string &name, CreateFunc func,
							   const std::string &parent = "");

    /**
     * Creates an instance by class name.
     */
	static Object *create(const std::string &name);

    /**
     * Checks if `child` inherits from `parent`.
     */
	static bool is_child_of(const std::string &child,
							const std::string &parent);

  private:
	static std::unordered_map<std::string, ClassInfo> &get_map();
};
#endif // GLASS_ENGINE_CLASSDB_HH