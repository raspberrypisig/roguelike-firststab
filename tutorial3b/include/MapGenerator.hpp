#pragma once

#include <algorithm>
#include <libtcod/bsp.hpp>
#include <libtcod/mersenne.hpp>
#include <memory>
#include <random>

#include "Map.hpp"
#include "Rectangle.hpp"

namespace tutorial {

constexpr static auto BSP_MAX_GENERATOR_LEVELS = 8;
constexpr static auto BSP_MIN_ROOM_WIDTH = 14;
constexpr static auto BSP_MIN_ROOM_HEIGHT = 6;
constexpr static auto BSP_MAX_H_RATIO = 2.5F;
constexpr static auto BSP_MAX_V_RATIO = 1.5F;

constexpr static auto MIN_ROOM_HEIGHT = 4;
constexpr static auto MIN_ROOM_NUMBER = 6;
constexpr static auto MAX_ROOM_NUMBER = 8;

Map generate_map(int width, int height);

class MapGenerator : public ITCODBspCallback {
 public:
  MapGenerator(int width, int height);
  bool visitNode(TCODBsp *node, void *userData) override;
  Map generate();
  Room generate_room(int x, int y, int width, int height);
  void cull();

 private:
  int maxRooms;
  int minRoomSize;
  int maxRoomSize;
  int width;
  int height;
  Map map;
};

}  // namespace tutorial