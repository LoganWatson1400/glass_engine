#include "ClassDB.hh"

using namespace std;

/*
	Global class registry (lazy-initialized)
	Stores all engine classes and their factory functions.
*/
unordered_map<string, ClassDB::ClassInfo> &ClassDB::get_map() {
	static unordered_map<string, ClassInfo> map;
	return map;
}

void ClassDB::register_class(const string &name, CreateFunc func,
							 const string &parent) {
	get_map()[name] = {func, parent};
}

Object *ClassDB::create(const string &name) {
	auto &map = get_map();
	auto it = map.find(name);

	if (it == map.end() || !it->second.creator)
		return nullptr;

	return it->second.creator();
}

bool ClassDB::is_child_of(const string &child, const string &parent) {
	auto &map = get_map();
	string current = child;

	while (!current.empty()) {
		if (current == parent)
			return true;

		auto it = map.find(current);
		if (it == map.end())
			return false;

		current = it->second.parent;
	}

	return false;
}