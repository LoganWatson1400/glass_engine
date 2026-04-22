#include "Camera.h"

void Camera::move(float dx, float dy, float dz)
{
    x += dx;
    y += dy;
    z += dz;
}