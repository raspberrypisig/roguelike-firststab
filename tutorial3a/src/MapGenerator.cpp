#include "MapGenerator.hpp"

namespace tutorial {

MapGenerator::MapGenerator(int width, int height) : map(Map(width, height)), width(width), height(height) {}

Map MapGenerator::generate() {
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(NULL, BSP_MAX_GENERATOR_LEVELS, BSP_MIN_ROOM_WIDTH, BSP_MIN_ROOM_HEIGHT, BSP_MAX_H_RATIO, BSP_MAX_V_RATIO);
  bsp.traverseInvertedLevelOrder(this, NULL);
  return map;
}

bool MapGenerator::visitNode(TCODBsp *node, void *userData) {
  if (!node->isLeaf()) {
    return true;
  }

  map.addRoom(generate_room(node->x, node->y, node->w, node->h));
  return true;
}

Room MapGenerator::generate_room(int x, int y, int width, int height) {
  int random_x = x;
  int random_y = y;
  int random_width = width - 1;
  int random_height = height - 1;

  // Put your custom random room generating algorithm here

  return Room(pos_t{random_x, random_y}, random_width, random_height);
}

}  // namespace tutorial
