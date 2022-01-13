#pragma once

#include <vector>

#include "Room.hpp"

namespace tutorial {

class Map {
 public:
  Map() = delete;
  Map(int width, int height);

 private:
  int width;
  int height;

  std::vector<Room> rooms;
};

}  // namespace tutorial