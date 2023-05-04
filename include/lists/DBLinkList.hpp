#ifndef ADS_INCLUDE_LISTS_DBLINKLIST_HPP_
#define ADS_INCLUDE_LISTS_DBLINKLIST_HPP_

#include <iostream>

#include "./DBListNode.hpp"

namespace ADS {
template <typename Type>
class DBLinkList {
 private:
  using Node = DBListNode<Type>;

 public:
  constexpr DBLinkList() noexcept {
    head = new Node(15);
    length = 0;
  }

  DBLinkList(const Type& t_element) {
    head = new Node(t_element);
    length++;
  }

  DBLinkList(const DBLinkList<Type>& t_list) { *this = t_list; }

  DBLinkList(DBLinkList<Type>&& t_list) noexcept { *this = std::move(t_list); }

  DBLinkList& operator=(const DBLinkList<Type>& t_list) {
    if (this != &t_list) {
      clear();
      head = t_list.head;
      length = t_list.length;
    }

    return *this;
  }

  DBLinkList& operator=(DBLinkList<Type>&& t_list) noexcept {
    if (this != &t_list) {
      clear();
      head = std::move(t_list.head);
      length = t_list.length;
    }

    return *this;
  }

  virtual ~DBLinkList() noexcept { clear(); }

  void clear() noexcept {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    length = 0;
  }

 public:
  void insert(const Type& t_element) {
    Node* n_node = new Node(t_element);

    if (head == nullptr) {
      head = n_node;
    } else {
      head->prev = n_node;
      n_node->next = head;
      head = n_node;
    }
  }

  void erase(const Type& t_element) {
    if (head == nullptr) {
      return;
    }

    Node* curr = head;
    while (curr != nullptr && curr->value != t_element) {
      curr = curr->next;
    }

    if (curr == nullptr) {
      return;
    }

    if (curr->prev == nullptr) {
      head = curr->next;
      if (head != nullptr) {
        head->prev = nullptr;
      }
    } else if (curr->next == nullptr) {
      curr->prev->next = nullptr;
    } else {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
    }

    delete curr;
    --length;
  }

  void MergeTwoLists(Node* l_t1, Node* l_t2) {
    if (l_t1 == nullptr) {
      l_t1 = l_t2;
      return;
    }

    Node* current = l_t1;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = l_t2;
  }

  [[nodiscard]] inline constexpr bool findValue(
      const Type& t_key) const noexcept {
    if (head->value == t_key || head->prev->value == t_key) {
      return true;
    }

    Node* temp = head;
    while (temp != nullptr) {
      if (temp->value == t_key) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  [[nodiscard]] inline constexpr int getMaxVal() const noexcept {
    int m_value = 0;

    while (head != nullptr) {
      m_value = std::max(m_value, head->value);
      head = head->next;
    }
    return m_value;
  }

  [[nodiscard]] inline constexpr int getMinVal() const noexcept {
    int min_val = 0;

    while (head != nullptr) {
      min_val = std::min(min_val, head->next);
      head = head->next;
    }
    return min_val;
  }

  inline constexpr void printReverse() const noexcept {
    if (head == nullptr) {
      return;
    }

    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }

    while (current != nullptr) {
      std::cout << current->value << ' ';
      current = current->prev;
    }
  }

  void printElements() {
    if (head == nullptr) {
      return;
    }

    while (head != nullptr) {
      std::cout << head->value << ' ';
      head = head->next;
    }
  }

 private:
  Node* head;
  unsigned int length;
};

}  // namespace ADS

#endif