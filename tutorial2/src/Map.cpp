#include "Map.hpp"
#include "Tile.hpp"

namespace tutorial {
Map::Map(int width, int height) : width(width), height(height) {
  tiles = std::vector<Tile>(width * height, Tile{.type = TileType::FLOOR});
}

} // namespace tutorial