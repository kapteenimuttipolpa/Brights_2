#pragma once
#include <iostream>
#include <vector>

struct object_data {
  std::string name;
};

static std::vector<object_data> object_storage{};

class large_object {
public:
  large_object();
  ~large_object();

  large_object(const large_object &other) {
    this->~large_object();
    object_storage.push_back(
        {std::string("object number ") + std::to_string(other.handle)});
  }

private:
  int handle = 0;
};

inline large_object::large_object() {
  int next_handle = object_storage.size();
  object_storage.push_back(
      {std::string("object number ") + std::to_string(next_handle)});
  handle = next_handle;
}

inline large_object::~large_object() {

  object_storage.erase(object_storage.begin() + handle);
}
