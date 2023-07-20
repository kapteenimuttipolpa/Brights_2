#include <iostream>
#include <ostream>
#include <vector>
namespace oma {
class point3d {
public:
  point3d(int32_t x, int32_t y, int32_t z);
  point3d() = default;
  ~point3d();
  friend std::ostream &operator<<(std::ostream &os, const point3d &point);
  point3d &operator+=(const point3d &point);
  point3d &operator-=(const point3d &point);
  int _x;
  int _y;
  int _z;

private:
};
point3d operator+(point3d point_a, point3d point_b);
point3d operator-(const point3d &point_a, const point3d &point_b);
bool operator<(const point3d &point_a, const point3d &point_b);

} // namespace oma