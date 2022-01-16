#pragma once

#include <libtcod/bsp.hpp>
#include <libtcod/mersenne.hpp>
#include <memory>

#include "Map.hpp"
#include "Rectangle.hpp"

namespace tutorial {

constexpr static auto BSP_MAX_GENERATOR_LEVELS = 8;
constexpr static auto BSP_MIN_ROOM_WIDTH = 14;  // This tells BSP algorithm that a partition can't be smaller than this width
constexpr static auto BSP_MIN_ROOM_HEIGHT = 6;  // This tells BSP algorithm that a partition can't be smaller than this width
constexpr static auto BSP_MAX_H_RATIO = 2.5F;
constexpr static auto BSP_MAX_V_RATIO = 1.5F;

Map generate_map(int width, int height);

class MapGenerator : public ITCODBspCallback {
 public:
  MapGenerator(int width, int height);

  bool visitNode(TCODBsp *node, void *userData) override;

  Map generate();

  Room generate_room(int x, int y, int width, int height);

 private:
  int maxRooms;
  int minRoomSize;
  int maxRoomSize;
  int width;
  int height;
  Map map;
};

}  // namespace tutorial