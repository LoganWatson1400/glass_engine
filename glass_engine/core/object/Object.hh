#ifndef GLASS_ENGINE_OBJECT_HH
#define GLASS_ENGINE_OBJECT_HH
#include <string>

class Object {
  public:
	virtual ~Object() = default;

	virtual const char *get_class_name() const = 0;

	virtual bool is_class(const std::string &name) const {
		return get_class_name() == name;
	}
};
#endif // GLASS_ENGINE_OBJECT_HH