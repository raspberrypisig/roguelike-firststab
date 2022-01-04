#pragma once

#include <SDL2/SDL.h>
#include <libtcod.h>

#include <string>

#include "Context.hpp"
#include "Entity.hpp"
#include "Position.hpp"

namespace tutorial {

class Engine {
 public:
  Engine(int width, int height, const std::string &title,
         const std::string &rexpaintpath, const std::string &font_path);
  ~Engine();

  void handle_input();
  bool is_running() const;
  void render();

 private:
  Context context;
  Entity player;
  tcod::Console console;
  tcod::Console offscreenConsole;
};

}  // namespace tutorial
