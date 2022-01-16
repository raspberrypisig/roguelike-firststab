#pragma once

#include <vector>

#include "Position.hpp"

namespace tutorial {

class Rectangle {
 public:
  Rectangle() = delete;
  Rectangle(pos_t top_left_origin, int width, int height);
  int width;
  int height;
  pos_t top_left;
  pos_t bottom_right;
};

using Room = Rectangle;
using Tunnel = Rectangle;

}  // namespace tutorial