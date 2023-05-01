#ifndef ADS_INCLUDE_TREES_AVLTREE_HPP_
#define ADS_INCLUDE_TREES_AVLTREE_HPP_

#include "AVLNode.hpp"
#include <memory>

namespace ADS {
template<typename Type>
class AVLTree: public AVLNode<Type> {
private:
    using Node = AVLNode<Type>;

    using const_reference = const Type&;

    using value_type = Type;

    using reference_type = Type&;

    template<typename T,typename TT>
    using is_base_of = typename std::enable_if_t<std::is_base_of<T,TT>::value, bool>; 

public:
    AVLTree() noexcept  { 
        root = new Node(10);
    }

    virtual ~AVLTree() noexcept { 
        if(root == nullptr) {
            return;
        }

        delete root;
    }  

    template<typename Derived, is_base_of<BSTree<Type>,Derived> = true> 
    void insert(const Type& t_element) { 
        Node *new_node = new Node(t_element);

        if(root == nullptr) { 
            root = new_node;
        }

        Node *current = nullptr;
        Node *temp = root;

        while(temp!=nullptr) {
           current = temp;
           if(temp->val<t_element) { 
               temp = temp->right;
           } else {
               temp = temp->left;
           }
        }

        if(current == nullptr) {
            current = new_node;
        } else if(current->val<t_element) {
            current->right = new_node;
        } else {
            current->left = new_node;
        }
        
    }

    template<typename Derived, is_base_of<AVLNode<Type>,Derived> = true> 
    void erase(const Type& t_element) {

    }

    template<typename Derived,is_base_of<AVLNode<Type>,Derived> = true>
    [[nodiscard]] const int getHeight(Node *node) const noexcept {
        if(node == nullptr) { return 0; }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return std::max(leftHeight,rightHeight) + 1;
    }

    template<typename Derived,is_base_of<AVLNode<Type>,Derived> = true>
    [[nodiscard]] int isBalanceTree(Node *node) const noexcept {
        if(node == nullptr) { return true; }

        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);

        return leftH - rightH;
    }
    
    void toBalanceTree(Node *node) { 
        int balance_t = isBalanceTree(node);
        if(balance_t > 1) { 

        } else if(balance_t < -1) {

        }
    }

    void rotateLeft(Node *node) { 

    }

    void rotateRight(Node *node) { 

    }

private:
    Node *root;
};

} // namespace ADS

#endif