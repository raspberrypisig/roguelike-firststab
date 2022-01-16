#pragma once

#include <vector>

#include "Rectangle.hpp"

namespace tutorial {

class Map {
 public:
  Map() = default;
  Map(int width, int height);
  int get_width() const;
  int get_height() const;
  void addRoom(Room room);

  std::vector<Room> rooms;
  std::vector<Tunnel> tunnels;

 private:
  int width;
  int height;
};

}  // namespace tutorial