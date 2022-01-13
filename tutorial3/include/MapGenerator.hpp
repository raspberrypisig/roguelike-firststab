#pragma once

#include <libtcod/bsp.hpp>
#include <libtcod/mersenne.hpp>
#include <memory>

#include "Map.hpp"

namespace tutorial {

constexpr static auto MAX_ROOMS = 8;
constexpr static auto MAX_ROOM_SIZE = 12;
constexpr static auto MIN_ROOM_SIZE = 6;

Map generate_map(int width, int height);

class MapGenerator : public ITCODBspCallback {
 public:
  MapGenerator() = default;

  bool visitNode(TCODBsp *node, void *userData) override;

  void generate(std::unique_ptr<Map> map);

 private:
  int maxRooms;
  int minRoomSize;
  int maxRoomSize;
  int width;
  int height;
};

}  // namespace tutorial