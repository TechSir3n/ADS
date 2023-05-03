#ifndef ADS_INCLUDE_LISTS_LINKLIST_HPP_
#define ADS_INCLUDE_LISTS_LINKLIST_HPP_

#include "ListNode.hpp"

namespace ADS {
template <typename Type> class LinkList {
  private:
    using Node = ListNode<Type>;

  public:
    constexpr LinkList() noexcept {
        head = new Node();
        length = 0;
    }

    LinkList(const Type& t_element) {
        head = new Node(t_element);
        length++;
    }

    LinkList(const LinkList<Type>& t_list) { *this = t_list; }

    LinkList(LinkList<Type>&& t_list) noexcept { *this = std::move(t_list); }

    LinkList& operator=(const LinkList<Type>& t_list) {
        if (this != &t_list) {
            clear();
            head = t_list.head;
            length = t_list.length;
        }

        return *this;
    }

    LinkList& operator=(LinkList<Type>&& t_list) noexcept {
        if (this != &t_list) {
            clear();
            head = std::move(t_list.head);
            length = t_list.length;
        }

        return *this;
    }

    virtual ~LinkList() noexcept { clear(); }

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
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = n_node;
    }

    void erase(const Type& t_element) {}

    [[nodiscard]] inline constexpr bool findValue() const noexcept { return true; }

    [[nodiscard]] inline constexpr int getMaxVal() const noexcept { return 1; }

    [[nodiscard]] inline constexpr int getMinVal() const noexcept { return 1; }

    [[nodiscard]] inline constexpr int size() const noexcept { return length; }

  private:
    Node* head;
    unsigned int length;
};

} // namespace ADS

#endif