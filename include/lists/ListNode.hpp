#ifndef ADS_INCLUDE_LISTS_LISTNODE_HPP_
#define ADS_INCLUDE_LISTS_LISTNODE_HPP_

namespace ADS {
template <typename Type>
struct ListNode {
  ListNode() = default;

  ListNode(const ListNode<Type>& t_node) = default;

  ListNode(ListNode<Type>&& t_node) = default;

  ListNode& operator=(const ListNode<Type>& _node) = default;

  ListNode& operator=(ListNode<Type>&& t_node) = default;

  ~ListNode() = default;

  ListNode(const Type& val) : value(val) {}

  ListNode(const Type& val, ListNode* t_next) : value(val), next(t_next) {}

 public:
  ListNode* next = nullptr;
  Type value = Type();
};

}  // namespace ADS

#endif