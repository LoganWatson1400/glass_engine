#pragma once
#include "world/nodes/Node3D.h"
#include "rendering/Mesh.h"

/// @brief A Node3D that holds a mesh to be rendered.
class MeshInstance : public Node3D {
public:
    Mesh mesh;
};