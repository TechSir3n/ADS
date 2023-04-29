#include <iostream>
#include <utility>

template <typename Type>
class TreeNode {
public:
    explicit TreeNode(const Type &t_val) : val(t_val), right(nullptr), left(nullptr) { }

    TreeNode() : val(Type()), right(nullptr), left(nullptr) { }

    explicit TreeNode(Type &&t_val, TreeNode *t_left, TreeNode *t_right) : 
        val(std::forward<Type>(t_val)), right(t_right), left(t_left) { }

    TreeNode(TreeNode &&t_node) noexcept { *this = std::move(t_node); }

    virtual ~TreeNode() noexcept { }
    
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