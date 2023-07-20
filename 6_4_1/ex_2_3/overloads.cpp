#include "overloads.hpp"
#include <cstdint>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <vector>
/* Some functions could maybe use refactoring */
namespace oma {
/**
 * @brief Construct a new point3d::point3d object
 *
 * @param x
 * @param y
 * @param z
 */
point3d::point3d(int32_t x, int32_t y, int32_t z) : _x(x), _y(y), _z(z) {}
/**
 * @brief overload << operator
 * to print the values
 * @param os
 * @param point
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const point3d &point) {
  os << "Point3D {x, y, z}: " << point._x << " " << point._y << " " << point._z
     << " \n";
  return os;
}
/**
 * @brief overload += operator
 * handle overflow errors
 * @param point
 * @return point3d&
 */
point3d &point3d::operator+=(const point3d &point) {
  int max = std::numeric_limits<int>::max();
  int64_t temp_x = static_cast<int64_t>(this->_x) + point._x;
  int64_t temp_y = static_cast<int64_t>(this->_y) + point._y;
  int64_t temp_z = static_cast<int64_t>(this->_z) + point._z;
  if (temp_x > max or temp_y > max or temp_z > max) {
    throw std::overflow_error("overflow at += overload");
  }
  this->_x += point._x;
  this->_y += point._y;
  this->_z += point._z;
  return *this;
}
/**
 * @brief overload -= operator
 * handle underflow errors
 * @param point
 * @return point3d&
 */
point3d &point3d::operator-=(const point3d &point) {
  point3d temp(_x, _y, _z);
  if (temp < point) {
    throw std::underflow_error(" underflow at -= overload");
  }
  this->_x -= point._x;
  this->_y -= point._y;
  this->_z -= point._z;
  return *this;
}
/**
 * @brief overload + operator
 * handle overflow errors
 * @param point_a
 * @param point_b
 * @return point3d
 */
point3d operator+(point3d point_a, point3d point_b) {
  int max = std::numeric_limits<int>::max();
  int64_t temp_x =
      static_cast<int64_t>(point_a._x) + static_cast<int64_t>(point_b._x);
  int64_t temp_y =
      static_cast<int64_t>(point_a._y) + static_cast<int64_t>(point_b._y);
  int64_t temp_z =
      static_cast<int64_t>(point_a._z) + static_cast<int64_t>(point_b._z);
  if (temp_x > max or temp_y > max or temp_z > max) {
    throw std::overflow_error("Overflow at + overload");
  }

  return point3d(point_a._x + point_b._x, point_a._y + point_b._y,
                 point_a._z + point_b._z);
}
/**
 * @brief overload - operator
 *  handle underflow error
 * @param point_a
 * @param point_b
 * @return point3d
 */
point3d operator-(const point3d &point_a, const point3d &point_b) {
  if (point_a < point_b) {
    throw std::underflow_error("Underflow at - overload");
  }
  point3d temp(point_a._x - point_b._x, point_a._y - point_b._y,
               point_a._z - point_b._z);
  return temp;
}
/**
 * @brief overload < operator
 *
 * @param point_a
 * @param point_b
 * @return true
 * @return false
 */
bool operator<(const point3d &point_a, const point3d &point_b) {
  int32_t total_a = point_a._x + point_a._y + point_a._z;
  int32_t total_b = point_b._x + point_b._y + point_b._z;
  if (total_a < total_b) {
    return true;
  }
  return false;
}
point3d::~point3d() {}
} // namespace oma