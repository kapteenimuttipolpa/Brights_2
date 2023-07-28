#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
namespace ui {
struct pos {
    int x = 0;
    int y = 0;
};
class widget {
  public:
    using ptr_vec = std::vector<std::shared_ptr<widget>>;
    using shared_ptr = std::shared_ptr<widget>;
    pos position;
    virtual ~widget() = default;
    virtual pos get_pos() = 0;
    virtual void on_click() const = 0;
    virtual void move_pos(int x, int y) = 0;
    virtual void whoami() const = 0;
    virtual void add_child(shared_ptr child) { children.push_back(child); }
    virtual ptr_vec get_children() { return children; }
    ptr_vec children;
};
class button : public widget {
  public:
    pos position;
    button() = default;
    button(const std::string &label) : _label(label) {}
    virtual pos get_pos() final { return position; }
    virtual void on_click() const final { std::cout << "Button pressed!\n"; }
    virtual void move_pos(int x, int y) {
        position.x = x;
        position.y = y;
    }
    virtual void whoami() const final {
        if (_label.empty()) {
            std::cout << "Button\n";
        } else {
            std::cout << "Button: " << _label << '\n';
        }
    }

  private:
    std::string _label;
};
} // namespace ui
