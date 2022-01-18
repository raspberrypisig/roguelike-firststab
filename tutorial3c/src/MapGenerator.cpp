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
    int distance = calculate_distance(reference_room.centre.x, reference_room.centre.y, r.centre.x, r.centre.y);
    return UnconnectedRoom({.room_index = i++, .distance = distance});
  });

  std::sort(unconnected_rooms.begin(), unconnected_rooms.end(), [](const UnconnectedRoom &r1, const UnconnectedRoom &r2) {
    return r1.distance < r2.distance;
  });

  int room_index = unconnected_rooms.front().room_index;
  dig(reference_room, map.rooms[room_index]);
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

/*
x1, y1 - coords of first room
w1, h1 - size of first room, etc.

if(x1 + w1 < x2 || x2 + w2 < x1) then vertical
if(y1 + h1 < y2 || y2 + h2 < y1) then horizontal
if(both) then random
if(none) they overleap and doesn't need to be connected via coridor

*/
void MapGenerator::dig(Room room1, Room room2) {
  //start digging
  int a = room1.bottom_right.x - room2.top_left.x;  // <0 room1 to the left of room2
  int b = room2.bottom_right.x - room1.top_left.x;  // <0 a vertical line doesn't exist that bisects both rooms
  int c = room1.bottom_right.y - room2.top_left.y;  // <0 room1 above room2
  int d = room2.bottom_right.y - room1.top_left.y;  // <0 a horizontal line doesn't exists that bisects both rooms

  if (a < 0 || b < 0) {
    // horizontal passage
    int x = std::min(room1.centre.x, room2.centre.x);
    int y = std::min(room1.centre.y, room2.centre.y);

    int v = std::max(room1.centre.x, room2.centre.x);
    int w = std::max(room1.centre.y, room2.centre.y);

    if (c > 0) {
      map.tunnels.push_back(Tunnel{pos_t{x, y}, std::abs(room2.centre.x - room1.centre.x), 1});
      map.tunnels.push_back(Tunnel{pos_t{v, y}, 1, std::abs(room2.centre.y - room1.centre.y)});
    } else {
      map.tunnels.push_back(Tunnel{pos_t{x, y}, std::abs(room1.centre.x - room2.centre.x), 1});
      map.tunnels.push_back(Tunnel{pos_t{v, y}, 1, std::abs(room2.centre.y - room1.centre.y)});
    }
    //map.tunnels.push_back(Tunnel{pos_t{x, y}, std::abs(room1.centre.x - room2.centre.x), 1});
    //map.tunnels.push_back(Tunnel{pos_t{x, y}, 1, std::abs(room2.centre.y - room1.centre.y)});
  }

  else {
    // vertical passage
  }
}

int calculate_distance(int x1, int y1, int x2, int y2) {
  int x_dif, y_dif;

  x_dif = x2 - x1;
  y_dif = y2 - y1;

  return x_dif * x_dif + y_dif * y_dif;
}

}  // namespace tutorial
