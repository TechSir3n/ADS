#ifndef ADS_INCLUDE_TREES_BSTREE_HPP_
#define ADS_INCLUDE_TREES_BSTREE_HPP_

#include <algorithm>
#include <climits>
#include <memory>
#include <queue>
#include <type_traits>

#include "TreeNode.hpp"

namespace ADS {
template <typename Type>
class BSTree : public TreeNode<Type> {
 private:
  using Node = TreeNode<Type>;

  using pointer_node = std::unique_ptr<TreeNode<Type>>;

  using value_type = Type;

  using reference_type = Type&;

  using const_reference = const Type&;

  template <typename T, typename TT>
  using is_base_of =
      typename std::enable_if_t<std::is_base_of<T, TT>::value, bool>;

 public:
  BSTree() noexcept { root = new Node(3); }

  constexpr BSTree(const std::initializer_list<Type>& t_list) {
    std::for_each(t_list.begin(), t_list.end(),
                  [&](auto& t_element) { insert(t_element); });
  }

  BSTree<Type>& operator=(const BSTree<Type>& t_node) {
    if (this != &t_node) {
      delete this->root;
      root = t_node.root;
    }

    return *this;
  }

  BSTree<Type>& operator=(BSTree<Type>&& t_node) {
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
  void insertNode(const Type& t_element) {
    Node* n_node = new Node(t_element);

    if (root == nullptr) {
      root = n_node;
      return;
    }

    Node* temp = root;
    Node* current = nullptr;

    while (temp != nullptr) {
      current = temp;
      if (temp->val < t_element) {
        temp = temp->right;
      } else {
        temp = temp->left;
      }
    }

    if (current == nullptr) {
      current = n_node;
    } else if (current->val < t_element) {
      current->right = n_node;
    } else {
      current->left = n_node;
    }
  }

  void erase(const Type& t_element) {
    if (root == nullptr) {
      return;
    }

    Node* parent = nullptr;
    Node* temp = root;
    while (temp != nullptr && temp->val != t_element) {
      parent = temp;
      if (temp->val < t_element) {
        temp = temp->right;
      } else {
        temp = temp->left;
      }
    }

    if (temp == nullptr) {
      return;
    }

    if (temp->right == nullptr && temp->left == nullptr) {
      if (parent != nullptr) {
        if (parent->left == temp) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
        delete temp;
      }
    } else if (temp->left == nullptr) {
      if (parent != nullptr) {
        if (parent->left == temp) {
          parent->left = temp->right;
        } else {
          parent->right = temp->right;
        }
      } else {
        root = temp->right;
      }
      delete temp;

    } else if (temp->right == nullptr) {
      if (parent != nullptr) {
        if (parent->left == temp) {
          parent->left = temp->left;
        } else {
          parent->right = temp->left;
        }
      } else {
        root = temp->left;
      }
      delete temp;

    } else {
      Node* minRight = temp->right;
      while (minRight->left != nullptr) {
        parent = minRight;
        minRight = minRight->left;
      }
      temp->val = minRight->val;
      if (parent == nullptr) {
        temp->right = minRight->right;
      } else {
        parent->left = minRight->left;
      }
      delete minRight;
    }
  }

  void copy_bstree(Node* node, Node*& node_copy) {
    if (node != nullptr) {
      node_copy = new Node(node->val);
      copy_bstree(node->left, node->left);
      copy_bstree(node->right, node_copy->right);
    }
  }

  [[nodiscard]] inline const Node* getMax(Node* node) const noexcept {
    if (node == nullptr) {
      return node;
    }

    Node* maxNode = node;
    while (maxNode->right != nullptr) {
      maxNode = maxNode->right;
    }

    return maxNode;
  }

  [[nodiscard]] inline const Node* getMin(Node* node) const noexcept {
    if (node == nullptr) {
      return node;
    }

    Node* minNode = node;
    while (minNode->left != nullptr) {
      minNode = minNode->left;
    }

    return minNode;
  }

  [[nodiscard]] const int countNodes() const noexcept {
    if (root == nullptr) {
      return 0;
    }

    std::queue<Node*> deq;
    deq.push(root);
    int count = 0;

    while (!deq.empty()) {
      Node* current = deq.front();
      deq.pop();
      count++;

      if (current->left != nullptr) {
        deq.push(current->left);
      }
      if (current->right != nullptr) {
        deq.push(current->right);
      }
    }
    return count;
  }

  template <typename Func>
  [[maybe_unused]] void preorderPrint(Node* t_node, Func fnc) const noexcept {
    if (t_node != nullptr) {
      fnc(root);
      preorderPrint(t_node->left, fnc);
      preorderPrint(t_node->right, fnc);
    }
  }

  template <typename Func>
  void postorderPrint(Node* t_node, Func fnc) const noexcept {
    if (t_node != nullptr) {
      postorderPrint(t_node->left, fnc);
      fnc(t_node);
      postorderPrint(t_node->right, fnc);
    }
  }

  template <typename Func>
  [[maybe_unused]] void revrorderPrint(Node* t_node, Func fnc) const noexcept {
    if (t_node != nullptr) {
      revrorderPrint(t_node->left, fnc);
      revrorderPrint(t_node->right, fnc);
      fnc(root);
    }
  }

  inline constexpr void printElements() noexcept {
    postorderPrint(root,
                   [](auto element) { std::cout << element->val << ' '; });
  }

 private:
  Node* root = nullptr;
};

}  // namespace ADS

#endif