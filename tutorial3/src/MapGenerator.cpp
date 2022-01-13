#include "MapGenerator.hpp"

namespace tutorial {

void MapGenerator::generate(std::unique_ptr<Map> map) {
  auto bsp{TCODBsp{0, 0, map.get()->get_width(), map.get()->get_height()}};
  bsp.splitRecursive(TCODRandom::getInstance(), 8, MAX_ROOM_SIZE, MIN_ROOM_SIZE, 1.5F, 1.5F);
  bsp.traverseInvertedLevelOrder(this, map.get());
}

bool MapGenerator::visitNode(TCODBsp *node, void *userData) {
  if (!node->isLeaf()) {
    return true;
  }

  return true;
}

Map generate_map(int width, int height) {
  auto map{Map{width, height}};
  MapGenerator generator;
  auto bsp{TCODBsp{0, 0, width, height}};
  bsp.splitRecursive(TCODRandom::getInstance(), 4, MAX_ROOM_SIZE, MIN_ROOM_SIZE, 1.5F, 1.5F);
  bsp.traverseInvertedLevelOrder(&generator, NULL);
  return map;
}

}  // namespace tutorial
