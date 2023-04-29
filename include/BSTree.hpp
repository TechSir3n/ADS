#include "TreeNode.hpp"
#include <climits>
#include <algorithm>

template <typename Type>
class BSTree : public TreeNode<Type>
{
public:
    using Node = TreeNode<Type>;

public:
    BSTree() noexcept {
        root = new Node(3);
    }

    constexpr BSTree(Node *root, const std::initializer_list<Type> &t_list) {
        std::for_each(t_list.begin(), t_list.end(), [&](auto &t_element)
                      { insert(t_element, root); });
    }

    BSTree<Type> &operator=(const BSTree<Type> &t_node) {
        if (this != &t_node) {
            delete this->root;
            root = t_node.root;
        }

        return *this;
    }

    BSTree<Type> &operator=(BSTree<Type> &&t_node)
    {
        if (this != &t_node) {
            delete this->root;
            root = std::move(t_node.root);
        }

        return *this;
    }

    virtual ~BSTree() noexcept {
        if (root == nullptr) {
            return;
        }

        delete root;
    }

public:
    void insertNode(const Type &t_element)
    {
        Node *n_node = new Node(t_element);

        if (root == nullptr) {
            root = n_node;
            return;
        }

        Node *current = root;
        while (true) {
            if (current->val < t_element) {
                if (current->right == nullptr) {
                    current->right = n_node;
                    return;
                } else {
                    current  = current->right;
                }

            } else {
                if(current->left==nullptr) {
                    current->left = n_node;
                    return;
                } else {
                    current = current->left;
                }
            }
        }
    }

    void erase(const Type &t_element) {

    }

    template<typename Func> 
    void preorderPrint(Node *t_node,Func fnc) { 
        if(t_node!=nullptr){
         preorderPrint(t_node->left,fnc);
         fnc(t_node);
         preorderPrint(t_node->right,fnc);
        }
    }

     void printElements() { 
       preorderPrint(root,[](auto element){
            std::cout<<element->val<<' ';
       });
    }

private:
    Node *root;
};