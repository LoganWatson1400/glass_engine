
#ifndef GLASS_ENGINE_NODE_HH
#define GLASS_ENGINE_NODE_HH

    #include <vector>
    #include <memory>
    #include <string>

    /// @brief Base class for all scene nodes.
    /// Manages the scene graph (parent/children) and lifecycle hooks.
    class Node {
        public:
            std::string name;
            Node* parent = nullptr;
            std::vector<std::unique_ptr<Node>> children;

            /// @brief Adds a child node under this node.
            void addChild(std::unique_ptr<Node> child);

            /// @brief Called once when the node enters the scene tree.
            virtual void onReady() {}

            /// @brief Called every frame.
            /// @param deltaTime Seconds since the last frame.
            virtual void onUpdate(float deltaTime) {}

            virtual ~Node() = default;
    }; //CLASS Node

#endif //GLASS_ENGINE_NODE_HH