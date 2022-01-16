#include "MapGenerator.hpp"

namespace tutorial {

MapGenerator::MapGenerator(int width, int height) : map(Map(width, height)), width(width), height(height) {}

Map MapGenerator::generate() {
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(NULL, BSP_MAX_GENERATOR_LEVELS, BSP_MIN_ROOM_WIDTH, BSP_MIN_ROOM_HEIGHT, BSP_MAX_H_RATIO, BSP_MAX_V_RATIO);
  bsp.traverseInvertedLevelOrder(this, NULL);
  cull();
  return map;
}

bool MapGenerator::visitNode(TCODBsp *node, void *userData) {
  if (!node->isLeaf()) {
    return true;
  }

  map.addRoom(generate_room(node->x, node->y, node->w, node->h));
  return true;
}

// We generate a room  for every BSP "leaf" partition. This will be culled later.
Room MapGenerator::generate_room(int x, int y, int width, int height) {
  int initial_x = x;
  int initial_y = y;
  int initial_width = width - 1;
  int initial_height = height - 1;

  int random_x = initial_x;
  int random_y = initial_y;
  int random_width = initial_width;
  int random_height = initial_height;

  // Put your custom random room generating algorithm here.
  random_width = TCODRandom::getInstance()->getInt(random_width / 2, random_width);
  random_height = TCODRandom::getInstance()->getInt(MIN_ROOM_HEIGHT, random_height);

  random_x += TCODRandom::getInstance()->getInt(0, initial_width - random_width);
  random_y += TCODRandom::getInstance()->getInt(0, initial_height - random_height);

  return Room(pos_t{random_x, random_y}, random_width, random_height);
}

void MapGenerator::cull() {
  std::random_device rd;
  std::mt19937 rng(rd());
  int room_count = TCODRandom::getInstance()->getInt(MIN_ROOM_NUMBER, MAX_ROOM_NUMBER);
  std::shuffle(map.rooms.begin(), map.rooms.end(), rng);
  map.rooms.erase(map.rooms.begin() + room_count, map.rooms.end());
}

}  // namespace tutorial
