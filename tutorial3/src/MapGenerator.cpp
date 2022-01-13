#include "MapGenerator.hpp"

namespace tutorial {

MapGenerator::MapGenerator(int max_rooms, int min_room_size, int max_room_size, int width,
                           int height) {}

std::unique_ptr<Map> MapGenerator::generate() { return nullptr; }
bool MapGenerator::visitNode(TCODBsp *node, void *userData) { return true; }

}  // namespace tutorial