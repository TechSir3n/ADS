#ifndef ADS_INCLUDE_TREES_AVLTREE_HPP_
#define ADS_INCLUDE_TREES_AVLTREE_HPP_

#include "TreeNode.hpp"
#include <algorithm>
#include <iomanip>
#include <queue>

template <typename Key> struct default_key {
    static Key value() { return Key(); }
};

template <typename Value> struct default_value {
    static Value value() { return Value(); }
};

namespace ADS {
template <typename Type, typename Key = default_key<Type>, typename Value = default_value<Type>>
class AVLTree {
  private:
    using Node = TreeNode<Type>;

    using const_reference = const Type&;

    using value_type = Type;

    using reference_type = Type&;

    template <typename T, typename TT>
    using is_base_of = typename std::enable_if_t<std::is_base_of<T, TT>::value, bool>;

  public:
    class Iterator {
      public:
        Iterator() : m_node(nullptr), tree(nullptr) {}

        Iterator(Node* node) : m_node(node), tree(nullptr) {}

        Iterator& operator++() {
            if (m_node->right != nullptr) {
                m_node = m_node->right;
                while (m_node->left != nullptr) {
                    m_node = m_node->left;
                }
            } else {
                Node* parent = m_node->parent;
                while (parent != nullptr && m_node == parent->right) {
                    m_node = parent;
                    parent = parent->parent;
                }
                m_node = parent;
            }
            return *this;
        }

        Iterator& operator--() {
            if (m_node == nullptr) {
                m_node = tree->root;

                if (m_node == nullptr) {
                    return *this;
                }

                while (m_node->right != nullptr) {
                    m_node = m_node->right;
                }
            } else if (m_node->left != nullptr) {
                m_node = m_node->left;

                while (m_node->right != nullptr) {
                    m_node = m_node->right;
                }
            } else {
                Node* parent = m_node->parent;
                while (parent != nullptr && m_node == parent->left) {
                    m_node = parent;
                    parent = parent->parent;
                }
                m_node = parent;
            }

            return *this;
        }

        Iterator begin() {
            Node* current;
            if (!current) {
                return Iterator(nullptr);
            }

            while (current != nullptr) {
                current = current->left;
            }

            return Iterator(current);
        }

        Iterator end() { return Iterator(nullptr); }

        std::pair<const Key, Value>& operator*() const {
            return m_node->val;
            ;
        }

        bool operator==(const Iterator& other) const { return m_node == other.m_node; }

        bool operator!=(const Iterator& other) const { return !(*this == other); }

      private:
        Node* m_node;
        AVLTree<Key, Value>* tree;
    };

  public:
    constexpr AVLTree() noexcept { root = new Node; }

    constexpr AVLTree(const std::initializer_list<Type>& t_list) noexcept {
        std::for_each(t_list.begin(), t_list.end(), [&](auto& element) { insert(element); });
    }

    virtual ~AVLTree() noexcept {
        if (root == nullptr) {
            return;
        }

        delete root;
    }

    AVLTree<Type>& operator=(AVLTree<Type>&& t_node) noexcept {
        if (this != &t_node) {
            *this = std::move(t_node);
        }

        return *this;
    }

    AVLTree<Type>& operator=(const AVLTree<Type>& t_node) noexcept {
        if (this != &t_node) {
            *this = t_node;
        }

        return *this;
    }

  public:
    void insert(const Type& t_element) {
        Node* new_node = new Node(t_element);

        if (root == nullptr) {
            root = new_node;
        }

        Node* current = nullptr;
        Node* temp = root;

        if constexpr (std::is_same_v<Type, std::pair<Key, Value>>) {
            while (temp != nullptr && temp->val.first != t_element.first) {
                current = temp;
                if (temp->val.first < t_element.first) {
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }

                if (!temp) {

                    if (current == nullptr) {
                        current = new_node;
                    } else if (current->val.first < t_element.first) {
                        current->right = new_node;
                    } else {
                        current->left = new_node;
                    }
                } else {
                    temp->val.first = t_element->val.first;
                }
            }
        } else {
            while (temp != nullptr) {
                current = temp;
                if (temp->val < t_element) {
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            }

            if (current == nullptr) {
                current = new_node;
            } else if (current->val < t_element) {
                current->right = new_node;
            } else {
                current->left = new_node;
            }
        }

        new_node->parent = current;
        root = toBalanceTree(root);
    }

    template <typename rKey, typename rValue> void erase(const std::pair<rKey, rValue>& key) {
        if (root == nullptr) {
            return;
        }

        Node* parent = nullptr;
        Node* temp = root;
        while (temp != nullptr && temp->val.first != key.first) {
            parent = temp;
            if (temp->val.first < key.first) {
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
            } else {
                root = nullptr;
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
                parent->left = minRight->right;
            }
            delete minRight;

            root = toBalanceTree(root);
        }
    }

    [[nodiscard]] Iterator find(const Type& key) const {
        Node* node = root;
        while (node != nullptr) {
            if (key == node->val) {
                return Iterator(node);
            } else if (key < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return nullptr;
    }

    [[nodiscard]] const int getHeight(Node* node) const noexcept {
        if (node == nullptr) {
            return 0;
        }
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    [[nodiscard]] int balanceFactor(Node* node) const noexcept {
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* toBalanceTree(Node* node) {
        if (balanceFactor(node) > 1) { // левое поддерево слишком высоко
            if (balanceFactor(node->left) < 0) {
                node->left = leftRotation(node->left);
            }
            node = rightRotation(node);
        } else if (balanceFactor(node) < -1) { // правое поддерево слишком высоко
            if (balanceFactor(node->right) > 0) {
                node->right = rightRotation(node->right);
            }
            node = leftRotation(node);
        }

        return node;
    }

    [[nodiscard]] Node* leftRotation(Node* node) noexcept {
        Node* t_node = node->right;
        Node* p_node = t_node->left;
        t_node->left = node;
        node->right = p_node;
        return t_node;
    }

    [[nodiscard]] Node* rightRotation(Node* node) noexcept {
        Node* t_node = node->left;
        Node* p_node = t_node->right;
        t_node->right = node;
        node->left = p_node;
        return t_node;
    }

    [[nodiscard]] inline constexpr Node* get_root() const noexcept { return root; }

    [[nodiscard]] inline Node* get_root() noexcept { return root; }

    template <typename Func> void inorderPrint(Node* node, Func fnc) const noexcept {
        if (node != nullptr) {
            inorderPrint(node->left, fnc);
            fnc(node);
            inorderPrint(node->right, fnc);
        }
    }

    void printPair(const TreeNode<std::pair<Key, Value>>* root) {
        if (root != nullptr) {
            printPair(root->left);
            std::cout << "Key:" << root->val.first << " Value: " << root->val.second << '\n';
            printPair(root->right);
        }
    }

    inline constexpr void printElements() noexcept {
        if constexpr (std::is_same_v<Type, std::pair<Key, Value>>) {
            printPair(root);
        } else {
            inorderPrint(root, [](auto element) {
                std::cout << "Value: " << element->val.first << "Value:" << element->val.second
                          << '\n';
            });
        }
    }

  private:
    Node* root = nullptr;
};

} // namespace ADS

#endif