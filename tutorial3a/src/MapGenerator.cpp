#include "MapGenerator.hpp"

namespace tutorial {

MapGenerator::MapGenerator(int width, int height) : map(Map(width, height)), width(width), height(height) {}

Map MapGenerator::generate() {
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(NULL, MAX_GENERATOR_LEVELS, MAX_ROOM_SIZE, MIN_ROOM_SIZE, MAX_H_RATIO, MAX_V_RATIO);
  bsp.traverseInvertedLevelOrder(this, NULL);
  return map;
}

bool MapGenerator::visitNode(TCODBsp *node, void *userData) {
  if (!node->isLeaf()) {
    return true;
  }

  int minx = node->x;
  int maxx = node->x + node->w;
  int miny = node->y;
  int maxy = node->y + node->h;

  /*
  minx = TCODRandom::getInstance()->getInt(minx, maxx - minRoomSize);
  miny = TCODRandom::getInstance()->getInt(miny, maxy - minRoomSize);
  maxx = TCODRandom::getInstance()->getInt(minx + minRoomSize, maxx);
  maxy = TCODRandom::getInstance()->getInt(miny + minRoomSize, maxy);
  */

  /*
  node->x = minx;
  node->y = miny;
  node->w = (maxx - minx + 1);
  node->h = (maxy - miny + 1);
  */

  node->w = node->w / 2;
  node->h = node->h / 2;
  node->x = minx + TCODRandom::getInstance()->getInt(0, 3);
  node->y = miny + TCODRandom::getInstance()->getInt(0, 3);
  ;

  map.addRoom(pos_t{node->x, node->y}, node->w, node->h);
  return true;
}

/*
Map generate_map(int width, int height) {
  MapGenerator generator(width, height);
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(TCODRandom::getInstance(), 4, MAX_ROOM_SIZE, MIN_ROOM_SIZE, 1.5F, 1.5F);
  bsp.traverseInvertedLevelOrder(&generator, NULL);
  return map;
}
*/

}  // namespace tutorial
