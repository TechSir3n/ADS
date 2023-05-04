#ifndef ADS_INCLUDE_LISTS_DBLISTNODE_HPP_
#define ADS_INCLUDE_LISTS_DBLISTNODE_HPP_

namespace ADS {
template <typename Type> struct DBListNode {
    DBListNode() = default;

    DBListNode(const DBListNode<Type>& t_node) = default;

    DBListNode(DBListNode<Type>&& t_node) = default;

    DBListNode& operator=(DBListNode<Type>&& t_node) = default;

    DBListNode& operator=(const DBListNode<Type>& t_node) = default;

    ~DBListNode() = default;

    DBListNode(const Type& val) : value(val), next(nullptr), prev(nullptr) {}

    DBListNode(const Type& val, DBListNode* t_next, DBListNode* t_prev)
        : value(val), next(t_next), prev(t_prev) {}

  public:
    DBListNode* next;
    DBListNode* prev;
    Type value;
};

} // namespace ADS

#endif