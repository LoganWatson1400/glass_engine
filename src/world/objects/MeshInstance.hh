
#ifndef GLASS_ENGINE_MESHINSTANCE_HH
#define GLASS_ENGINE_MESHINSTANCE_HH

#include "world/nodes/Node3D.hh"
#include "rendering/Mesh.hh"

/// @brief A Node3D that holds a mesh to be rendered.
class MeshInstance : public Node3D {
public:
    Mesh mesh;
};

#endif //GLASS_ENGINE_MESHINSTANCE_HH