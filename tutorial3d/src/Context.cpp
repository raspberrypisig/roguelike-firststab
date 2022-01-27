#include "Context.hpp"

namespace tutorial {

Context::Context(tcod::Console &console, const std::string &window_title, const std::string &font_path) {
  params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
  params.console =
      console.get();  // Derive the window size from the console size.
  params.window_title = window_title.c_str();
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = 0;  // This allows some user-control of the context.
  params.argv = nullptr;
  params.renderer_type = TCOD_RENDERER_SDL2;

  //Tileset example using a Code Page 437 font.
  //tileset = tcod::load_tilesheet(font_path, {16, 16}, tcod::CHARMAP_CP437);
  tileset = tcod::load_tilesheet(font_path, {16, 16}, tcod::CHARMAP_CP437);
  params.tileset = tileset.get();

  //Debugging
  //auto map = params.tileset->character_map;
  //auto moo = params.tileset->character_map_length;
  //auto moo2 = params.tileset->tiles_count;

  tcodContext = tcod::new_context(params);
}

void Context::update(tcod::Console &console) {
  tcodContext->present(console);
}

void draw_char(tcod::Console &console, pos_t pos, int icon,
               TCOD_ColorRGBA foreground_color,
               TCOD_ColorRGBA background_color) {
  //
  console.at({pos.x, pos.y}) = {icon, foreground_color, background_color};
}

void blit(tcod::Console &src, tcod::Console &dest) { tcod::blit(dest, src); }

void draw_rooms(tcod::Console &console, Map map) {
  for (const auto &room : map.rooms) {
    //draw floor
    tcod::draw_rect(console, {room.top_left.x + 2, room.top_left.y + 1, room.width - 3, room.height - 2}, FLOOR_ICON, TCOD_ColorRGB{128, 255, 0}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);

    //draw horizontal and vertical walls
    tcod::draw_rect(console, {room.top_left.x + 1, room.top_left.y, room.width - 1, 1}, WALL_HORIZONTAL_ICON, TCOD_ColorRGB{255, 128, 0}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);
    tcod::draw_rect(console, {room.bottom_right.x, room.top_left.y + 1, 1, room.height - 1}, WALL_VERTICAL_ICON, TCOD_ColorRGB{255, 128, 0}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);
    tcod::draw_rect(console, {room.top_left.x + 1, room.bottom_right.y, room.width - 1, 1}, WALL_HORIZONTAL_ICON, TCOD_ColorRGB{255, 128, 0}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);
    tcod::draw_rect(console, {room.top_left.x, room.top_left.y + 1, 1, room.height - 1}, WALL_VERTICAL_ICON, TCOD_ColorRGB{255, 128, 0}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);

    //draw wall corners

    console.at({room.top_left.x, room.top_left.y}).ch = WALL_TOP_LEFT_CORNER_ICON;
    console.at({room.top_left.x, room.top_left.y}).fg = TCOD_ColorRGB{255, 128, 0};
    console.at({room.top_left.x, room.top_left.y}).bg = TCOD_ColorRGB{0, 0, 0};

    console.at({room.top_left.x, room.bottom_right.y}).ch = WALL_BOTTOM_LEFT_CORNER_ICON;
    console.at({room.top_left.x, room.bottom_right.y}).fg = TCOD_ColorRGB{255, 128, 0};
    console.at({room.top_left.x, room.bottom_right.y}).bg = TCOD_ColorRGB{0, 0, 0};

    console.at({room.bottom_right.x, room.top_left.y}).ch = WALL_TOP_RIGHT_CORNER_ICON;
    console.at({room.bottom_right.x, room.top_left.y}).fg = TCOD_ColorRGB{255, 128, 0};
    console.at({room.bottom_right.x, room.top_left.y}).bg = TCOD_ColorRGB{0, 0, 0};

    console.at({room.bottom_right.x, room.bottom_right.y}).ch = WALL_BOTTOM_RIGHT_CORNER_ICON;
    console.at({room.bottom_right.x, room.bottom_right.y}).fg = TCOD_ColorRGB{255, 128, 0};
    console.at({room.bottom_right.x, room.bottom_right.y}).bg = TCOD_ColorRGB{0, 0, 0};
  }

  for (const auto &corridor : map.tunnels) {
    //tcod::draw_rect(console, {corridor.top_left.x, corridor.top_left.y, corridor.width, corridor.height}, FLOOR_ICON, TCOD_ColorRGB{255, 0, 255}, TCOD_ColorRGB{0, 0, 0}, TCOD_BKGND_SET);
  }
}

}  // namespace tutorial