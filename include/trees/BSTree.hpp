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

    constexpr BSTree(Node *root, const std::initializer_list<Type> &t_list)  {
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

        Node * temp = root;
        Node *current = nullptr;

        while(temp!=nullptr) {
            current = temp;
            if(temp->val<t_element) {
                temp = temp->right;
            } else {
                temp =  temp->left;
            }
        }

        if(current == nullptr) {
             current = n_node;
        } else if(current->val<t_element) {
            current->right = n_node;
        } else {
            current->left = n_node;
        }
    }

    void erase(const Type &t_element) {
        if(root == nullptr){
            return;
        }

        Node *parent = nullptr;
        Node *temp = root;
        while(temp!=nullptr && temp->val!=t_element){
            parent = temp;
            if(temp->val<t_element) { 
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        if(temp == nullptr) { return; }
      
        if(temp->right == nullptr && temp->left == nullptr) {
            if(parent!=nullptr) {
                if(parent->left == temp) {
                    parent->left = nullptr;
                } else { 
                    parent->right = nullptr;
                }
                delete temp;
            }
        } else if(temp->left == nullptr) {
            if(parent!=nullptr) {
                if(parent->left == temp) { 
                    parent->left = temp->right;
                } else {
                    parent->right = temp->right;
                }
            } else {
                root = temp->right;
            }
          delete temp;

        } else if(temp->right == nullptr) {
            if(parent!=nullptr) {
                if(parent->left == temp) {
                    parent->left = temp->left;
                } else {
                    parent->right = temp->left;
                }
            } else {
                root = temp->left;
            }
            delete temp;

        } else {
            Node *minRight = temp->right;
            while(minRight->left!=nullptr) { 
                parent = minRight;
                minRight = minRight->left;
            }
            temp->val = minRight->val;
            if(parent == nullptr) {
                temp->right = minRight->right;
            } else {
                parent->left = minRight->left;
            }
            delete minRight;
        }
    }

    [[nodiscard]] const Node * getMax(Node *node) const noexcept {
        if(node == nullptr) {
            return node;
        }

        Node *maxNode = node;
        while(maxNode->right!=nullptr) {
            maxNode = maxNode->right;
        }

        return maxNode;
    }

    [[nodiscard]] const Node *getMin(Node *node) const noexcept {
        if(node == nullptr) {
            return node;
        }

        Node *minNode = node;
        while(minNode->left!=nullptr) {
            minNode = minNode->left;
        }

        return minNode;
    }

    [[nodiscard]] int countNodes(Node *node) const noexcept {
        if(root == nullptr) {
            return 0;
        } else {
           int count = 1;
           count+=countNodes(node->left);
           count+=countNodes(node->right);
           return count;
        }
    }

    [[nodiscard]] bool isBalanceTree() const noexcept {

        return true;
    }

    template<typename Func> 
    [[maybe_unused]] void preorderPrint(Node *t_node,Func fnc) const noexcept { 
        if(t_node!=nullptr) {
            fnc(root);
            preorderPrint(t_node->left,fnc);
            preorderPrint(t_node->right,fnc);
        }
    }

    template<typename Func>
   void postorderPrint(Node* t_node,Func fnc) const noexcept {
        if(t_node!=nullptr) {
         postorderPrint(t_node->left,fnc);
         fnc(t_node);
         postorderPrint(t_node->right,fnc);
        }
    }

    template<typename Func> 
    [[maybe_unused]] void revrorderPrint(Node* t_node,Func fnc) const noexcept {
        if(t_node!=nullptr) {
            revrorderPrint(t_node->left,fnc);
            revrorderPrint(t_node->right,fnc);
            fnc(root);
        }
    }

    constexpr void printElements() noexcept { 
        postorderPrint(root,[](auto element) {
            std::cout<<element->val<<' ';
       });
    }   

private:
    Node *root;
};