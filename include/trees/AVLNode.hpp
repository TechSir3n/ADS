#ifndef ADS_INCLUDE_TREES_AVLNODE_HPP_
#define ADS_INCLUDE_TREES_AVLNODE_HPP_

#include "TreeNode.hpp"

namespace ADS {
template<typename Type>
class AVLNode : public TreeNode<Type> {
public:
   explicit AVLNode() noexcept : 
       TreeNode<Type>(Type(),nullptr,nullptr) { }

   explicit  AVLNode(const Type &val) :
        TreeNode<Type>(val) { }

   explicit  AVLNode(Type &&val,AVLNode *t_right,AVLNode* t_left) :
        TreeNode<Type>(std::move(val),t_right,t_left) { }

   AVLNode(AVLNode &&avl_node):TreeNode<Type>(std::move(avl_node)) { }

   AVLNode(const AVLNode &avl_node) : TreeNode<Type>(avl_node) { }

   virtual ~AVLNode() noexcept { }
public:
    AVLNode & operator=(const AVLNode<Type> &t_node) noexcept {
        if(this!=&t_node) {
            height = std::exchange(t_node.height,0);
            TreeNode<Type>::operator  = (t_node);
        }

        return *this;
    }

    AVLNode & operator=(AVLNode<Type> &&t_node) noexcept {
        if(this!=&t_node) {
            height = std::move(t_node.height);
            TreeNode<Type>::operator = (std::move(t_node));
        }

        return *this;
    }
    
private:
    unsigned int height;
};

} // namespace ADS

#endif 