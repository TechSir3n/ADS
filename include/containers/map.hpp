#ifndef ADS_INCLUDE_CONTAINERS_MAP_HPP_
#define ADS_INCLUDE_CONTAINERS_MAP_HPP_

#include "../trees/AVLTree.hpp"

namespace ADS {
template <typename Key, typename Value> class Map {
  private:
    using const_value = const Value;

    using reference_const = const Value&;

    using value_type = Value;

    using size_type = std::size_t;

    using const_key = Key;

  public:
    Map() {}

    Map(const std::initializer_list<Value>& t_value) {
        std::for_each(t_value.begin(), t_value.end(), [](auto& t_value) { insert(t_value); });
    }

    Map(const Map<Key, Value>& t_map) {}

    ~Map() = default;

    Map& operator=(Map&&) = default;

    Map& operator=(const Map&) = default;

  public:
    Key& at(const Key& key) { 
        auto val = avl.find(key);
        return *val;
    }

    Key& operator[](const Key& key) {
         auto val = avl.find(key);
        return *val;
    }

  public:
    inline void insert(const std::pair<const_key, value_type>& pair) { avl.insert(pair); }

    inline void insert(const Key& key, const Value& value) { avl.insert({key, value}); }

    inline void erase(const Key& key) { avl.erase(std::make_pair(key, 0)); }

    bool empty() const noexcept {
        if (avl.root == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    size_type size() const noexcept {
        int sz = avl.getHeight();
        if (sz == 0) {
            return 0u;
        } else {
            return sz;
        }
    }

    void swap(Map& other) { std::swap(avl, other.avl); }

    void merge(Map& other) {}

    bool contains(const Key& t_key) {
        auto contain = avl.find(t_key);
        if (contain == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    void printData() { avl.printElements(); }

  private:
    AVLTree<std::pair<Key, Value>> avl;
};
} // namespace ADS
#endif