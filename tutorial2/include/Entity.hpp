#pragma once

#include "Position.hpp"
#include <SDL2/SDL.h>
#include <libtcod.h>

namespace tutorial {
struct Entity {
public:
  Entity(pos_t pos);
  pos_t pos;
};
} // namespace tutorial