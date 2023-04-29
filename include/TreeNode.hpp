#include <iostream>
#include <utility>

template <typename Type>
class TreeNode {
public:
    explicit TreeNode(Type &&t_val) : 
        val(std::forward<Type>(t_val)), right(nullptr), left(nullptr) { }

    TreeNode() : val(Type()), right(nullptr), left(nullptr) { }

    explicit TreeNode(Type &&t_val, TreeNode *t_left, TreeNode *t_right) : 
        val(std::forward<Type>(t_val)), right(t_right), left(t_left) { }

    TreeNode(TreeNode &&t_node) noexcept { *this = std::move(t_node); }

    virtual ~TreeNode() { }

public:
    void preorderPrint(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->val << ' ';
        preorderPrint(node->left);
        preorderPrint(node->right);
    }

    void postorderPrint(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        postorderPrint(node->left);
        std::cout << node->val << ' ';
        postorderPrint(node->right);
    }

    void reversePrint(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        reversePrint(node->left);
        reversePrint(node->right);
        std::cout << node->val << ' ';
    }

    int CountNodes(TreeNode *node) {
        int count = 0;
        if (node == nullptr) {
            return 0;
        } else {
            count = 1;
            count += CountNodes(node->left);
            count += CountNodes(node->right);
        }

        return count;
    }

protected:
    TreeNode &operator=(TreeNode<Type> &t_node) noexcept {
        if (this != &t_node) {
            val = std::exchange(t_node.val, Type());
            left = std::exchange(t_node.left, nullptr);
            right = std::exchange(t_node.right, nullptr);
        }
        return *this;
    }

public:
    Type val;
    TreeNode *right;
    TreeNode *left;
};