#ifndef ADS_INCLUDE_TREES_RBTREE_HPP
#define ADS_INCLUDE_TREES_RBTREE_HPP

#include "TreeNode.hpp"

namespace ADS {
template<typename Key,typename Value>
class RBTree {
public:
    RBTree() noexcept { }

    virtual ~RBTree() noexcept { }

private:
    Key key;
    Value val;
};

} // namespace ADS
#endif