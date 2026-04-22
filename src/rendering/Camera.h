#pragma once

class Camera
{
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    void move(float dx, float dy, float dz);
};