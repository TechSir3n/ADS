#include "TreeNode.hpp"
#include <climits>

template <typename Type>
class BSTree : protected TreeNode<Type>
{
public:
    using Node = TreeNode<Type>;

public:
    BSTree() {}

    virtual ~BSTree() {}

public:
    Node *insert(Type &&t_element, Node *root) {
        if (root == nullptr) {
            root = new Node(std::forward<Type>(t_element));
        } else if (root->val > t_element) {
            root->left = insert(std::forward<Type>(t_element), root->left);
        } else {
            root->right = insert(std::forward<Type>(t_element), root->right);
        }

        return root;
    }

    Node *erase(Type &&t_element, Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        if (!findElement(root, (std::forward<Type>(t_element)))) {
            std::cerr << "Element not found";
        }

        if (root->val > t_element) {
            root->left = erase(std::forward<Type>(t_element), root->left);
        } else if (root->val < t_element) {
            root->right = erase(std::forward<Type>(t_element), root->right);
        } else {
            if (root->left == nullptr && root->right) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                Node *temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                Node *temp = root;
                root = root->left;
                delete temp;
            } else {
                Node *temp = new Node();
                temp->val = findMaxNode(root);
                root->val = temp->val;
                root->right = erase(std::forward<Type>(temp->val),root->right);
            }
        }
        return root;
    }

    int findMaxNode(Node *node) {
        if (node == nullptr) {
            return INT_MIN;
        }

        int maxLeftVal = INT_MIN;
        if (node->left != nullptr) {
            maxLeftVal = std::max(maxLeftVal, node->left->val);
            maxLeftVal = std::max(maxLeftVal, findMaxNode(node->left));
        }

        maxLeftVal = std::max(maxLeftVal, findMaxNode(node->right));
        return maxLeftVal;
    }

    bool findElement(Node *node, Type &&k_element) {
        if (node == nullptr || node->val == k_element) {
            return true;
        }

        if (node->val > k_element) {
            return findElement(node->left, std::forward<Type>(k_element));
        }

        return findElement(node->right,std::forward<Type>(k_element));
    }
};