#include "TreeNode.hpp"

template<typename Type>
class AVLNode {
public:
   explicit AVLNode() noexcept : value(Type()),left(nullptr),right(nullptr) { }

   explicit  AVLNode(const Type &val) : value(val),right(nullptr),left(nullptr) { }

   explicit  AVLNode(Type &&val,TreeNode *t_right,TreeNode* t_left) :
         value(std::move(val)),right(t_right),left(t_left) { }

   AVLNode(AVLNode &&avl_node) { *this = std::move(avl_node);}

   AVLNode(const AVLNode &avl_node ) { *this = avl_node; }

   virtual ~AVLNode() noexcept { }

private:
    Type value;
    AVLNode *left;
    AVLNode *right;
};