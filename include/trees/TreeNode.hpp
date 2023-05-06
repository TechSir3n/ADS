#ifndef ADS_INCLUDE_TREES_TREENODE_HPP_
#define ADS_INCLUDE_TREES_TREENODE_HPP_

#include <iostream>
#include <utility>

namespace ADS {
template <typename Type> struct TreeNode {
  public:
    explicit TreeNode(const Type& t_val)
        : val(t_val), right(nullptr), left(nullptr), parent(nullptr) {}

    TreeNode() : val(Type()), right(nullptr), left(nullptr), parent(nullptr) {}

    explicit TreeNode(Type&& t_val, TreeNode* t_left, TreeNode* t_right, TreeNode* t_parent)
        : val(std::move(t_val)), right(t_right), left(t_left), parent(t_parent) {}

    TreeNode(TreeNode&& t_node) noexcept { *this = std::move(t_node); }

    TreeNode(const TreeNode& t_node) noexcept { *this = t_node; }

    virtual ~TreeNode() noexcept {}

  public:
    TreeNode& operator=(const TreeNode<Type>& t_node) noexcept {
        if (this != &t_node) {
            val = std::exchange(t_node.val, Type());
            left = std::exchange(t_node.left, nullptr);
            right = std::exchange(t_node.right, nullptr);
            parent = std::exchange(t_node.parent, nullptr);
        }
        return *this;
    }

    TreeNode& operator=(TreeNode<Type>&& t_node) noexcept {
        if (this != &t_node) {
            val = std::move(t_node.val);
            left = std::move(t_node.left);
            right = std::move(t_node.right);
            parent = std::move(t_node.parent);
        }

        return *this;
    }

  public:
    Type val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent;
};

} // namespace ADS

#endif