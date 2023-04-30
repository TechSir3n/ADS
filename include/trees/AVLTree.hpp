#include "AVLNode.hpp"
#include <memory>

template<typename Type>
class AVLTree: protected AVLNode<Type> {
private:
    using Node = AVLNode<Type>;
    using pointer_node = std::unique_ptr<AVLNode<Type>>;
    using const_reference = const Type&;
    using value_type = Type;
    using reference_type = Type&;

public:
    AVLTree() noexcept  { }

    virtual ~AVLNode() noexcept { }
    
private:
    Node *root;
};