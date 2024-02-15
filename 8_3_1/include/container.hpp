#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <algorithm>
#include <initializer_list> // for init list
#include <iostream>         // for printing
#include <limits>           // for limits
#include <stdexcept>        // for exceptions
namespace oma {
template <typename T, size_t Size> class array {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  iterator begin() { return m_array_ptr; }
  iterator end() { return m_array_ptr + Size; }
  const_iterator begin() const { return m_array_ptr; }
  const_iterator end() const { return m_array_ptr + Size; }

public:
  array() noexcept { m_array_ptr = new T[Size]{}; } // constructor

  // move constructor
  array(array &&other) noexcept {
    this->m_array_ptr = other.m_array_ptr;
    other.m_array_ptr = nullptr;
  }

  // copy constructor
  array(const array &other) noexcept {
    m_array_ptr = new T[Size]{};
    std::copy(other.m_array_ptr, other.m_array_ptr + Size, m_array_ptr);
  }

  // init list constructor
  array(std::initializer_list<T> &&init_list) noexcept {
    m_array_ptr = new T[init_list.size()]{};
    std::move(init_list.begin(), init_list.end(), m_array_ptr);
  }

  // function for swapping elements
  void swap(array &other) {
    T *temp = m_array_ptr;
    m_array_ptr = other.m_array_ptr;
    other.m_array_ptr = temp;
  }
  // get the size
  constexpr size_t size() const noexcept { return Size; }

  // get the max size
  constexpr size_t max_size() const noexcept {
    return std::numeric_limits<size_t>::max();
  }

  // check if empty
  constexpr bool empty() const noexcept { return begin() == end(); }

  // destructor
  ~array() { delete[] m_array_ptr; }

public: // overloads
  // move assignment overload
  array &operator=(array &&other) noexcept {
    this->~array();
    this->m_array_ptr = other.m_array_ptr;
    other.m_array_ptr = nullptr;
    return *this;
  }

  array &operator=(const array &other) noexcept {
    if (this != &other) {
      array<T, Size> temp{other};
      delete[] m_array_ptr;
      swap(temp);
      temp.m_array_ptr = nullptr;
    }
    return *this;
  }

  // operator [] overload
  T &operator[](size_t index) {
    if (index > Size - 1) {
      throw std::runtime_error("");
    }
    return m_array_ptr[index];
  }

  // == overload
  constexpr bool operator==(const array &other) const noexcept {
    return std::equal(this->begin(), this->end(), other.begin(), other.end());
  }

  // != overload
  constexpr bool operator!=(const array<T, Size> &other) const noexcept {
    return !(*this == other);
  }

private:
  T *m_array_ptr;
};

// another swap function
template <typename T, size_t Size>
constexpr void swap(array<T, Size> &lhv, array<T, Size> &rhv) {
  lhv.swap(rhv);
}
} // namespace oma

// clang-format on
#endif