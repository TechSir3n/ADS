#ifndef ADS_INCLUDE_CONTAINERS_STACK_HPP_
#define ADS_INCLUDE_CONTAINERS_STACK_HPP_

#include <algorithm>
#include <iostream>
#include <vector>

namespace ADS {
template <typename Type> class Stack {
  private:
    using value_type = Type;

    using reference_type = Type&;

    using const_reference = const Type&;

    using size_type = std::size_t;

  public:
    Stack(size_type init_sz = 10) : sz(init_sz) { data.reserve(sz); }

    Stack(const std::initializer_list<value_type>& t_list) {
        std::for_each(t_list.begin(), t_list.end(), [](auto& t_element) { push(t_element); });
    }

    Stack(const Stack& st) = default;

    Stack(Stack&& st) = default;

    ~Stack() noexcept = default;

    Stack& operator=(Stack&& st) = default;

    Stack& operator=(const Stack& st) = default;

  public:
    inline constexpr const Type& top() const {
        if (empty()) {
            throw std::runtime_error("Cannot get top element in stack");
        }
        return data.back();
    }

    [[nodiscard]] inline constexpr bool empty() const { return size() == 0 ? true : false; }

    [[nodiscard]] inline constexpr size_type size() const noexcept { return data.size(); }

    inline void push(const_reference t_element) {
        if (data.size() >= sz) {
            throw std::out_of_range("overflow stack !");
        }
        data.push_back(t_element);
    }

    inline void pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty !");
        }

        data.pop_back();
    }

    inline void swap(Stack& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
    }

    inline constexpr void showElements() {
        if (!empty()) {
            std::for_each(data.begin(), data.end(),
                          [](auto& t_element) { std::cout << t_element << ' '; });
        }
    }

  private:
    std::vector<Type> data;
    size_type sz;
};

} // namespace ADS

#endif