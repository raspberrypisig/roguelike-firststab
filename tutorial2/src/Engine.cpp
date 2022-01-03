#include "Engine.hpp"

namespace tutorial {

constexpr auto player_icon = '@';
constexpr auto player_foreground_color =
    TCOD_ColorRGB{.r = 128, .g = 128, .b = 128};
constexpr auto player_background_color =
    TCOD_ColorRGB{.r = 128, .g = 255, .b = 0};
constexpr auto player_position = pos_t{.x = 40, .y = 12};

Engine::Engine(int width, int height, const std::string &title,
               const std::string &path)
    : player(Entity{player_position}) {
  tcod::Console c{width, height};
  console = tcod::Console(c);
  context = Context(console, title);
  offscreenConsole = tcod::Console(std::move(tcod::load_xp(path).at(0)));
}

bool Engine::is_running() const {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    return false; // Exit.
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
    if (console.in_bounds({new_player_pos.x, new_player_pos.y}))
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

} // namespace tutorial