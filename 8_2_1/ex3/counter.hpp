#include <cstddef>
#include <iostream>
#include <string>
class counter {
public:
  counter(const char *data) {
    std::cout << "created!\n";
    m_data = data;
    ++instance_count;
  }
  counter(counter &&other) {
    std::cout << "moved!\n";
    this->m_data = other.m_data;
    other.is_moved_object = true;
    other.m_data = nullptr;
  }
  counter(const counter &obj) {}
  ~counter() {
    std::cout << "destroyed!\n";
    m_data = nullptr;
    if (!is_moved_object)
      --instance_count;
  }
  static size_t get_count() { return instance_count; }

  counter &operator=(counter &&other) {
    std::cout << "moved!\n";
    if (this != &other) {
      this->m_data = other.m_data;
      this->instance_count = other.instance_count;
      other.m_data = nullptr;
      --other.instance_count;
    }
    other.is_moved_object = true;
    return *this;
  }
  void print_data() const { std::cout << m_data << '\n'; }

private:
  inline static size_t instance_count;
  const char *m_data;
  bool is_moved_object = false;
};