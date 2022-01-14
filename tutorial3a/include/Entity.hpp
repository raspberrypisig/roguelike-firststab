#pragma once

#include <SDL2/SDL.h>
#include <libtcod.h>

#include "Position.hpp"

namespace tutorial {
struct Entity {
 public:
  Entity(pos_t pos);
  pos_t pos;
};
}  // namespace tutorial