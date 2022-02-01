#pragma once

#include <array>
#include <vector>

#include "Rectangle.hpp"

namespace tutorial {

using Doors = std::array<pos_t, 2>;

class Map {
 public:
  Map() = default;
  Map(int width, int height);
  int get_width() const;
  int get_height() const;
  void addRoom(Room room);

  std::vector<Room> rooms;
  std::vector<Tunnel> tunnels;
  std::vector<Doors> doors;

 private:
  int width;
  int height;
};

}  // namespace tutorial