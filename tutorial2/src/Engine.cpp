#include "Engine.hpp"

namespace tutorial {

constexpr auto PLAYER_ICON = "@";

Engine::Engine(int width, int height, const std::string &title)
    : player_pos(pos_t{width / 2, height / 2}) {
  console = tcod::Console{width, height}; // Main console.
  offscreenConsole = tcod::Console{width, height};
  // Configure the context.
  Context ctx(console, title);
}

bool Engine::IsRunning() const {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    return false; // Exit.
  }

  return true;
}

void Engine::HandleInput() {
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

void Engine::Render() {
  TCOD_console_clear(console.get());
  tcod::print(console, {player_pos.x, player_pos.y}, PLAYER_ICON, std::nullopt,
              std::nullopt);
  context->present(console);
}

Engine::~Engine() { TCOD_quit(); }

} // namespace tutorial