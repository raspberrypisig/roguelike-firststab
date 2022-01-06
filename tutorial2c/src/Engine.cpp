#include "Engine.hpp"

namespace tutorial {

constexpr auto player_icon = tcod::CHARMAP_CP437[138];
constexpr auto player_foreground_color =
    TCOD_ColorRGBA{.r = 128, .g = 128, .b = 128, .a = 255};
constexpr auto player_background_color =
    TCOD_ColorRGBA{.r = 128, .g = 255, .b = 0, .a = 255};
constexpr auto wall_icon = tcod::CHARMAP_CP437[65];
constexpr auto floor_icon_unicode = tcod::CHARMAP_CP437[43];

constexpr auto LIGHT_BLUE = tcod::ColorRGB{95, 205, 228};
constexpr auto WHITE = tcod::ColorRGB{255, 255, 255};

Engine::Engine(int width, int height, const std::string &title,
               const std::string &path, const std::string &font_path)
    : player(Entity{pos_t{.x = width / 2, .y = height / 2}}),
      console(tcod::Console{width, height}) {
  context = Context(console, title, font_path);

  offscreenConsole = tcod::Console(std::move(tcod::load_xp(path).at(0)));
  //auto boo = offscreenConsole.at({13, 5}).ch;

  for (auto &tile : offscreenConsole) {
    if (tile.ch == 0x20) {
      tile.ch = 0;
      tile.bg = LIGHT_BLUE;
    }

    tile.ch = tcod::CHARMAP_CP437[tile.ch];
  }
}

bool Engine::is_running() const {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      return false;  // Exit.
  }

  return true;
}

void Engine::handle_input() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_KEYDOWN:
      auto scancode = event.key.keysym.scancode;
      auto new_player_pos = player.pos;
      switch (scancode) {
        case SDL_SCANCODE_DOWN:
          new_player_pos.y += 1;
          break;
        case SDL_SCANCODE_UP:
          new_player_pos.y -= 1;
          break;
        case SDL_SCANCODE_LEFT:
          new_player_pos.x -= 1;
          break;
        case SDL_SCANCODE_RIGHT:
          new_player_pos.x += 1;

          break;
      }
      if (console.in_bounds({new_player_pos.x, new_player_pos.y}) && offscreenConsole.at({new_player_pos.x, new_player_pos.y}).ch != wall_icon)
        player.pos = new_player_pos;
      break;
  }
}

void Engine::render() {
  blit(offscreenConsole, console);
  draw_char(console, player.pos, player_icon, player_foreground_color,
            player_background_color);
  context.update(console);
}

Engine::~Engine() { TCOD_quit(); }

}  // namespace tutorial