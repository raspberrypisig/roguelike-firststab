#include "Console.hpp"

namespace tutorial {
Console::Console(int width, int height, std::string &title) {
  console = tcod::Console{width, height}; // Main console.

  // Configure the context.
  auto params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION; // This is required.
  params.console =
      console.get(); // Derive the window size from the console size.
  params.window_title = "Libtcod Project";
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = 0; // This allows some user-control of the context.
  params.argv = nullptr;

  // Tileset example using a Code Page 437 font.
  // "terminal8x8_gs_ro.png" must be in the working directory.
  // auto tileset = tcod::load_tilesheet("terminal8x8_gs_ro.png", {16, 16},
  // tcod::CHARMAP_CP437); params.tileset = tileset.get();

  context = tcod::new_context(params);
}
} // namespace tutorial