#include "Transform.hh"
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

mat4 Transform::toMatrix() const {
	mat4 m = mat4(1.0f);

	m = translate(m, position);

	// Rotation applied in YXZ order (yaw, pitch, roll)
	m = rotate(m, radians(rotation.y), vec3(0.0f, 1.0f, 0.0f));
	m = rotate(m, radians(rotation.x), vec3(1.0f, 0.0f, 0.0f));
	m = rotate(m, radians(rotation.z), vec3(0.0f, 0.0f, 1.0f));

	m = glm::scale(m, scale);

	return m;
}