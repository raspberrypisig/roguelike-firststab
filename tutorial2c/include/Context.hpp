#pragma once

#include <SDL2/SDL.h>

#include <libtcod.hpp>

#include "Position.hpp"

namespace tutorial {

class Context {
 public:
  Context() = default;
  Context(tcod::Console &console, const std::string &window_title, const std::string &font_path);
  void update(tcod::Console &console);

 private:
  TCOD_ContextParams params;
  tcod::ContextPtr tcodContext;
  tcod::Tileset tileset;
};

// Should these free functions be put somewhere else (modern C++ and all)?
std::vector<tcod::ConsolePtr> new_console_from_rexpaint(const std::string &path);
void draw_char(tcod::Console &console, pos_t pos, int icon,
               TCOD_ColorRGBA foreground_color,
               TCOD_ColorRGBA background_color);
void blit(tcod::Console &src, tcod::Console &dest);
}  // namespace tutorial
