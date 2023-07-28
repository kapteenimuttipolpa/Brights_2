#include "interface.hpp"
#include <iostream>
#include <memory>
int main() {
    auto new_window = std::make_shared<ui::button>();
    auto btn = std::make_shared<ui::button>();
    auto nested_btn = std::make_shared<ui::button>("Grandkid");

    new_window->add_child(btn);
    btn->add_child(nested_btn);

    auto kids = new_window->get_children();
    for (const auto &kid : kids) {
        kid->whoami();
        auto grandkids = kid->get_children();
        for (const auto &grandkid : grandkids) {
            grandkid->whoami();
        }
    }

    return 0;
}