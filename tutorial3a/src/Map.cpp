#include "Map.hpp"

namespace tutorial {

Map::Map(int width, int height) : width(width), height(height) {}

int Map::get_width() const {
  return width;
}

int Map::get_height() const {
  return height;
}

void Map::addRoom(Room room) {
  rooms.push_back(room);
}

}  // namespace tutorial
