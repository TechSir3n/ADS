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
    Stack() { data.reserve(sz++); }

    Stack(const std::initializer_list<Type>& t_list) {
        std::for_each(t_list.begin(), t_list.end(), [](auto& t_element) { push(t_element); });
    }

    Stack(const Stack& st) = default;

    Stack(Stack&& st) = default;

    ~Stack() noexcept = default;

    Stack& operator=(Stack&& st) = default;

    Stack& operator=(const Stack& st) = default;

  public:
    inline constexpr const Type& top() const noexcept { return data.back(); }

    inline constexpr bool empty() const noexcept { return data.empty(); }

    inline constexpr size_type size() const noexcept { return data.size(); }

    inline void push(const_reference t_element) {
        if (data.size() > sz) {
            throw std::out_of_range("overflow stack !");
        }
        data.push_back(t_element);
    }

    inline void pop() {
        if (!data.empty()) {
            throw std::out_of_range("Stack is empty !");
        }

        data.pop_back();
        sz--;
    }

    inline void swap(Stack&& other) { std::swap(data, other); }

    inline constexpr void showElements() {
        if (!empty()) {
            std::for_each(data.begin(), data.end(),
                          [](auto& t_element) { std::cout << t_element << ' '; });
        }
    }

  private:
    std::vector<Type> data;
    size_type sz = 0;
};

} // namespace ADS

#endif