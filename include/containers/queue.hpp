#ifndef ADS_INCLUDE_CONTAINERS_QUEUE_HPP_
#define ADS_INCLUDE_CONTAINERS_QUEUE_HPP_

#include <algorithm>
#include <iostream>
#include <vector>

namespace ADS {
template <typename Type> class Queue {
  private:
    using value_type = Type;

    using reference_type = Type&;

    using const_reference = const Type&;

    using size_type = std::size_t;

  public:
    Queue() {
        capacity = 10;
        que = new Type[capacity];
        sz = 0;
        frontI = -1;
        rearI = 0;
    }

    ~Queue() { delete[] que; }

    Queue(const std::initializer_list<value_type>& t_list)
        : sz(t_list.size()), frontI(0), rearI(sz - 1), capacity(sz), que(new Type[capacity]) {
        std::copy(t_list.begin(), t_list.end(), que);
    }

    Queue(const Queue& q) = default;

    Queue(Queue&& q) = default;

    Queue& operator=(const Queue& q) = default;

    Queue& operator=(Queue&& q) = default;

  public:
    [[nodiscard]] const_reference front() {
        if (empty()) {
            throw std::out_of_range("Coudn't get element from front queuq");
        }

        return que[frontI];
    }

    [[nodiscard]] const_reference back() {
        if (empty()) {
            throw std::out_of_range("Coudn't get element from back queuq");
        }

        return que[rearI];
    }

    [[nodiscard]] inline constexpr bool empty() const noexcept { return size() == 0; }

    [[nodiscard]] inline size_type size() const noexcept { return sz; }

    inline void push(const_reference val) {
        if (sz == capacity) {
            throw std::runtime_error("Cannot push element to queue,doesn't have enough size");
        }

        if (frontI == -1) {
            frontI = 0;
        }

        que[rearI] = val;
        rearI = (rearI + 1) % capacity;
        sz++;
    }

    inline void pop() {
        if (sz == 1) {
            throw std::out_of_range("There are no elements in the Queue to pop");
        }

        frontI = (frontI + 1) % capacity;
        sz--;

        if (sz == 0) {
            frontI = -1;
            rearI = 0;
        }
    }

    inline void swap(Queue& other) {
        std::swap(capacity, other.capacity);
        std::swap(sz, other.sz);
        std::swap(frontI, other.frontI);
        std::swap(rearI, other.rearI);
    }

    inline constexpr void showElements() const noexcept {
        for (int i = frontI; i < rearI; ++i) {
            std::cout << que[i] << ' ';
        }
    }

  private:
    Type* que;
    size_type sz;
    int frontI;
    int rearI;
    int capacity;
};

} // namespace ADS
#endif