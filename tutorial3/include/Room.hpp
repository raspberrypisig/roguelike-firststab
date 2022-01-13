#pragma once

#include <vector>

#include "Position.hpp"

namespace tutorial {

class Room {
 public:
  Room() = delete;
  Room(pos_t top_left_origin, int width, int height);
  pos_t getCenter() const;
  pos_t getTopLeft() const;
  std::vector<pos_t> getInner() const;
  bool intersects(Room& other) const;

 private:
  pos_t top_left;
  pos_t bottom_right;
  int width;
  int height;
};

}  // namespace tutorial