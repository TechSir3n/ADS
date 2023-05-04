#ifndef ADS_INCLUDE_CONTAINERS_MAP_HPP_
#define ADS_INCLUDE_CONTAINERS_MAP_HPP_

#include "../trees/AVLTree.hpp"

namespace ADS {
template <typename Key, typename Value> class Map {
  private:
    using const_value = const Value;
    using reference_const = const Value&;
    using value_type = Value;

  public:
    Map() : t_key(Key()), t_value(Value()) {}

    Map(const std::initializer_list<Value>& t_value) {}

    Map(const Map<Key, Value>& t_map) {}

    ~Map() = default;

    Map& operator=(Map&&) = default;

    Map& operator=(const Map&) = default;

  public:
    void insert(const std::pair<Key, Value>& pair) {
        AVLTree<std::pair<Key, Value>> avl;
        avl.insert(pair);
    }

    bool empty() const noexcept {}

    size_t size() const noexcept {}

    size_t max_size() const noexcept {}

    void clear();

    void swap(Map& other) {}

    void merge(Map& other) {}

    bool contains(const Key& t_key);

  private:
    Key t_key;
    Value t_value;
};
} // namespace ADS
#endif