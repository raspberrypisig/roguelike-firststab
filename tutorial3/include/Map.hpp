#pragma once

#include <vector>

#include "Room.hpp"

namespace tutorial {

class Map {
 public:
  Map() = default;
  Map(int width, int height);
  int get_width() const;
  int get_height() const;

 private:
  int width;
  int height;

  std::vector<Room> rooms;
};

}  // namespace tutorial