#include "MapGenerator.hpp"

namespace tutorial {

MapGenerator::MapGenerator(int width, int height) : map(Map(width, height)), width(width), height(height) {}

Map MapGenerator::generate() {
  generate_rooms();
  generate_corridors();
  return map;
}

void MapGenerator::generate_rooms() {
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(NULL, BSP_MAX_GENERATOR_LEVELS, BSP_MIN_ROOM_WIDTH, BSP_MIN_ROOM_HEIGHT, BSP_MAX_H_RATIO, BSP_MAX_V_RATIO);
  bsp.traverseInvertedLevelOrder(this, NULL);
  cull();
}

void MapGenerator::generate_corridors() {
  std::vector<ConnectedRoom> connected_rooms{ConnectedRoom{.room_index = 0, .distance = 0}};
  std::vector<UnconnectedRoom> unconnected_rooms;
  Room &reference_room = map.rooms.front();

  int i = 1;
  std::transform(map.rooms.begin() + 1, map.rooms.end(), std::back_inserter(unconnected_rooms), [&i, &reference_room](const Room &r) mutable {
    int distance = manhattan_distance(reference_room.centre.x, reference_room.centre.y, r.centre.x, r.centre.y);
    return UnconnectedRoom({.room_index = i++, .distance = distance});
  });
  unconnected_rooms.erase(unconnected_rooms.begin());
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
  // Put your custom random room generating algorithm here.

  int initial_x = x;
  int initial_y = y;
  int initial_width = width - 2;
  int initial_height = height - 2;

  int random_x = initial_x;
  int random_y = initial_y;
  int random_width = initial_width;
  int random_height = initial_height;

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

int manhattan_distance(int x1, int x2, int y1, int y2) {
  int x_dif, y_dif;

  x_dif = x2 - x1;
  y_dif = y2 - y1;
  if (x_dif < 0)
    x_dif = -x_dif;
  if (y_dif < 0)
    y_dif = -y_dif;

  return x_dif + y_dif;
}

}  // namespace tutorial
