/**
 * @file grid2d.hpp
 * @author Ville Inkinen
 * @brief grid2d.
 * I'll keep updating this since it seems pretty useful

 * utils::grid2d<T> grid(size_t, size_t) initialises grid
 * with given size. Values will be zero.
 *
 *
 * @version 0.1
 * @date 2023-07-24
 *
 *
 */
#ifndef GRID2D_HPP
#define GRID2D_HPP
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>
namespace utils {
// clang-format off
// I need to change my clang format options so that it puts
// template <typename T> on its own row
template <typename T> class grid2d {
  public:
    using value_type        = T;
    using reference         = T &;
    using const_reference   = const T &;
    using storage_type      = std::vector<T>;
    using iterator          = typename storage_type::iterator;
    using const_iterator    = typename storage_type::const_iterator;
    using difference_type   = typename storage_type::difference_type;
    using size_type         = typename storage_type::size_type;
    // clang-format on
    grid2d(const size_type height, const size_type width)
        : _height(height), _width(width) {
        if (height < 0 or width < 0) {
            throw std::range_error("Negative size");
        }
        if (height * width > _cells.max_size()) {
            throw std::runtime_error("size larger than std::vector max_size()");
        }
        _cells.resize(width * height);
    }
    grid2d() noexcept = default;
    ~grid2d() noexcept {};
    reference operator()(size_type height, size_type width) {
        if (width > _width or height > _height)
            throw std::out_of_range("");
        return _cells[height * _width + width];
    }
    value_type at(size_type height, size_type width) {
        // currently using vector so .at() will throw
        // if out of bounds
        size_type index = height * _width + width;
        return _cells.at(index);
    }
    void resize(size_type new_width, size_type new_height) {
        // return if nothing changes
        if (new_width == _width and new_height == _height) {
            return;
        }
        // Check that new size isn't too large
        if (new_width * new_height > _cells.max_size()) {
            throw std::runtime_error("size larger than std::vector max_size()");
        }
        // for the moment this works, but there might be an issue
        // when using grid of strings etc
        // where values will be uninitialized to nothing
        storage_type new_grid(new_height * new_width);
        for (size_type i = 0; i < std::min(new_height, _height); ++i) {
            for (size_type j = 0; j < std::min(new_width, _width); ++j) {
                new_grid[i * new_width + j] = _cells[i * _width + j];
            }
        }
        _cells = new_grid;
        _width = new_width;
        _height = new_height;
    }
    void print() const {
        for (size_type i = 0; i < _height * _width; i++) {
            std::cout << _cells[i] << ' ';
            if ((i + 1) % _width == 0) {
                std::cout << '\n';
            }
        }
        std::cout << '\n';
    }
    size_type width() { return _width; }
    size_type height() { return _height; }
    bool empty() { return begin() == end(); }
    // clang-format off
    iterator        begin()            { return _cells.begin();   }
    iterator        end()              { return _cells.end();     }
    const_iterator  begin()      const { return _cells.begin();   }
    const_iterator  end()        const { return _cells.end();     }
    size_type       size()       const { return _height * _width; }
    

  private:
    size_type       _height;
    size_type       _width;
    std::vector<T>  _cells;
};
} // namespace utils

#endif // !GRID2D_HPP
