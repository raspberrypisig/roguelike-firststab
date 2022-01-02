#pragma once

#include "Context.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include <SDL2/SDL.h>
#include <libtcod.h>
#include <string>

namespace tutorial {

class Engine {

public:
  Engine(int width, int height, const std::string &title,
         const std::string &rexpaintpath);
  ~Engine();

  void handle_input();
  bool is_running() const;
  void render();

private:
  Context context;
  tcod::Console console;
  tcod::Console offscreenConsole;
  // std::vector<tcod::ConsolePtr> offscreenConsoles;
  pos_t player_pos;
  Entity player;
};

} // namespace tutorial
