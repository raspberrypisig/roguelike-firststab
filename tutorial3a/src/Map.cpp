#include "Map.hpp"

namespace tutorial {

Map::Map(int width, int height) : width(width), height(height) {}

int Map::get_width() const {
  return width;
}

int Map::get_height() const {
  return height;
}

void Map::addRoom(pos_t top_left, int w, int h) {
  rooms.push_back(Room{top_left, w, h});
}

}  // namespace tutorial
