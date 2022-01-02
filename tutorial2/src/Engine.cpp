#include "Engine.hpp"

namespace tutorial {

constexpr auto player_icon = '@';
constexpr auto player_color = TCOD_ColorRGB{.r = 255, .g = 255, .b = 255};

Engine::Engine(int width, int height, const std::string &title,
               const std::string &path)
    : player_pos(pos_t{.x = width / 2, .y = height / 2}),
      player(Entity{player_pos, player_icon, player_color}) {

  tcod::Console c{width, height};
  console = tcod::Console(c);
  context = Context(console, title);
  offscreenConsole = tcod::Console(std::move(tcod::load_xp(path).at(0)));
  // offscreenConsoles = new_console_from_rexpaint(path);
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
    switch (scancode) {
    case SDL_SCANCODE_DOWN:
      player_pos.y += 1;
      break;
    case SDL_SCANCODE_UP:
      player_pos.y -= 1;
      break;
    case SDL_SCANCODE_LEFT:
      player_pos.x -= 1;
      break;
    case SDL_SCANCODE_RIGHT:
      player_pos.x += 1;
      break;
    }
    break;
  }
}

void Engine::render() {
  // do some work
  tutorial::blit(offscreenConsole, console);
  context.update(console);
}

Engine::~Engine() { TCOD_quit(); }

} // namespace tutorial