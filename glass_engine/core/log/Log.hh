#ifndef GLASS_ENGINE_LOG_HH
#define GLASS_ENGINE_LOG_HH

#include <iostream>
#include <source_location>
#include <string>

namespace core::log {
enum class Level { Info, Warn, Error };

inline const char *level_string(Level level) {
	switch (level) {
	case Level::Info:
		return "INFO";
	case Level::Warn:
		return "WARN";
	case Level::Error:
		return "ERROR";
	default:
		return "UNKNOWN";
	}
}

inline void write(Level level, const char *message, const char *file, int line) {
	std::cout << "[" << level_string(level) << "]"
			  << ":" << line << " " << message << std::endl;
}
} // namespace core::log

#define LOG_INFO(msg)                                                          \
	do {                                                                       \
		::core::log::write(::core::log::Level::Info, msg, __FILE__, __LINE__); \
	} while (0)

#define LOG_WARN(msg)                                                          \
	do {                                                                       \
		::core::log::write(::core::log::Level::Warn, msg, __FILE__, __LINE__); \
	} while (0)

#define LOG_ERROR(msg)                                                         \
	do {                                                                       \
		::core::log::write(::core::log::Level::Error, msg, __FILE__, __LINE__);\
	} while (0)

#endif // GLASS_ENGINE_LOG_HH