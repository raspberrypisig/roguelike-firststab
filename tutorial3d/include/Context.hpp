#pragma once

#include <SDL2/SDL.h>

#include <libtcod.hpp>

#include "Map.hpp"
#include "Position.hpp"

namespace tutorial {

constexpr static auto WALL_ICON = tcod::CHARMAP_CP437[205];
constexpr static auto WALL_HORIZONTAL_ICON = tcod::CHARMAP_CP437[205];
constexpr static auto WALL_VERTICAL_ICON = tcod::CHARMAP_CP437[186];
constexpr static auto WALL_TOP_LEFT_CORNER_ICON = tcod::CHARMAP_CP437[201];
constexpr static auto WALL_TOP_RIGHT_CORNER_ICON = tcod::CHARMAP_CP437[187];
constexpr static auto WALL_BOTTOM_LEFT_CORNER_ICON = tcod::CHARMAP_CP437[200];
constexpr static auto WALL_BOTTOM_RIGHT_CORNER_ICON = tcod::CHARMAP_CP437[188];
constexpr auto FLOOR_ICON = tcod::CHARMAP_CP437[249];

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
void draw_rooms(tcod::Console &console, Map map);

}  // namespace tutorial
