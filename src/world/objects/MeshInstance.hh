#pragma once
#include "world/nodes/Node3D.hh"
#include "rendering/Mesh.hh"

/// @brief A Node3D that holds a mesh to be rendered.
class MeshInstance : public Node3D {
public:
    Mesh mesh;
};