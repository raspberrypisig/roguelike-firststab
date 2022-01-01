#include "Context.hpp"

namespace tutorial {

Context::Context(tcod::Console &console, const std::string &window_title) {
  params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION; // This is required.
  params.console =
      console.get(); // Derive the window size from the console size.
  params.window_title = window_title.c_str();
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = 0; // This allows some user-control of the context.
  params.argv = nullptr;
}

tcod::ContextPtr Context::create_new_context() {
  return tcod::new_context(params);
}

} // namespace tutorial