#pragma once

#include "Position.hpp"
#include <SDL2/SDL.h>
#include <libtcod.h>
#include <string>

namespace tutorial {

class Engine {

public:
  Engine(int width, int height, const std::string &title);
  ~Engine();

  void HandleInput();
  bool IsRunning() const;
  void Render();

private:
  tcod::ContextPtr context;
  tcod::Console console;
  pos_t player_pos;
};

} // namespace tutorial
