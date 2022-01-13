#pragma once

#include <libtcod/bsp.hpp>
#include <memory>

#include "Map.hpp"

namespace tutorial {
class MapGenerator : public ITCODBspCallback {
 public:
  MapGenerator(int max_rooms, int min_room_size, int max_room_size, int width,
               int height);

  bool visitNode(TCODBsp *node, void *userData) override;

  std::unique_ptr<Map> generate();

 private:
  int maxRooms;
  int minRoomSize;
  int maxRoomSize;
  int width;
  int height;
};

}  // namespace tutorial