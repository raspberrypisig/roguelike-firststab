#include "Room.hpp"

namespace tutorial {
Room::Room(pos_t top_left_origin, int width, int height) : top_left(top_left_origin),
                                                           bottom_right(pos_t{.x = top_left_origin.x + width, .y = top_left_origin.y + height}),
                                                           width(width),
                                                           height(height) {}

pos_t Room::getCenter() const {
  return pos_t{
      .x = top_left.x + width / 2,
      .y = top_left.y + height / 2};
}

std::vector<pos_t> Room::getInner() const {
  std::vector<pos_t> inner;
  for (int x = top_left.x + 1; x < bottom_right.x; ++x) {
    for (int y = top_left.y + 1; y < bottom_right.y; ++y) {
      inner.push_back(pos_t{x, y});
    }
  }
  return inner;
}

bool Room::intersects(Room& other) const {
  return (top_left.x <= other.bottom_right.x && bottom_right.x >= other.top_left.x && top_left.y <= other.bottom_right.y && bottom_right.y >= other.top_left.y);
}

}  // namespace tutorial