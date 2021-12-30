#pragma once

#include "Tile.hpp"

#include <vector>

namespace tutorial {

class Map {

public:
  Map(int width, int height);

private:
  int width;
  int height;
  std::vector<Tile> tiles;
};

} // namespace tutorial