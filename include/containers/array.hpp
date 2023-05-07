#ifndef ADS_INCLUDE_CONTAINERS_ARRAY_HPP_
#define ADS_INCLUDE_CONTAINERS_ARRAY_HPP_

#include <algorithm>
#include <iostream>
#include <limits>

namespace ADS {
template <typename Type, std::size_t N> class Array {
  private:
    using value_type = Type;

    using reference_type = Type&;

    using const_reference = const Type&;

    using size_type = std::size_t;

    using iterator = Type*;

    using const_iterator = const Type*;

  public:
    Array() {}

    Array(const std::initializer_list<value_type>& t_list) {
        std::copy(t_list.begin(), t_list.end(), m_data);
    }

    Array(const Array& q) = default;

    Array(Array&& q) = default;

    ~Array() = default;

    Array& operator=(const Array& q) = default;

    Array& operator=(Array&& q) = default;

  public:
    const_reference at(size_type pos) {
        if (pos >= N) {
            throw std::out_of_range("Array::at index out of range");
        }
        return m_data[pos];
    }

    const_reference front() { return m_data[0]; }

    const_reference back() { return m_data[N - 1]; }

    reference_type operator[](size_type pos) {
        if (pos >= N) {
            std::out_of_range("Array::[] index out of range");
        }
        return m_data[pos];
    }
    const_reference operator[](size_type pos) const {

        if (pos >= N) {
            std::out_of_range("Array::[] index out of range");
            return m_data[pos];
        }
    }

    iterator data() noexcept { return m_data; }

    const_iterator data() const noexcept { return m_data; }

    inline constexpr bool empty() const noexcept { return size() == 0; }

    inline constexpr size_type size() noexcept { return N; }

    size_type max_size() { return std::numeric_limits<size_type>::max(); }
    
    void swap(Array&& other) { std::swap_ranges(m_data, m_data + N, other.m_data); }

    void fill(const_reference value) { std::fill_n(m_data, N, value); }

    void showElements() { 
      std::for_each(m_data,m_data+N,[](const_reference element) {
          std::cout<<element<<' ';
      });
    }

  private:
    Type m_data[N];
};
} // namespace ADS
#endif