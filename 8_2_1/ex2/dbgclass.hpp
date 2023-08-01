#include <iostream>

template <bool is_enabled> class dbg {
public:
  dbg() {
    ++default_calls;
    if (is_enabled)
      std::cout << default_calls << " : "
                << "default constructor\n";
  };
  dbg(const dbg &other) {
    ++copy_calls;
    if (is_enabled)
      std::cout << copy_calls << " : "
                << "copy constructor\n";
  }
  dbg(dbg &&other) {
    ++move_calls;
    if (is_enabled)
      std::cout << move_calls << " : "
                << "move constructor\n";
  }
  ~dbg() {
    ++destructor_calls;
    if (is_enabled)
      std::cout << destructor_calls << " : "
                << "destructor\n";
  }
  inline static int default_calls = 0;
  inline static int move_calls = 0;
  inline static int copy_calls = 0;
  inline static int destructor_calls = 0;

private:
};