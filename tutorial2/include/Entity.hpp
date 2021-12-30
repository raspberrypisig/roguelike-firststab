#pragma once

#include "Position.hpp"
#include <SDL2/SDL.h>
#include <libtcod.h>

namespace tutorial {
class Entity {
public:
  Entity(pos_t pos, char icon, TCODColor color);

  void SetPos(pos_t pos);

  pos_t GetPos() const;
  void Render();

private:
  pos_t pos;
  char icon;
  TCODColor color;
};
} // namespace tutorial
