#include "Context.hpp"

namespace tutorial {

Context::Context(tcod::Console &console, const std::string &window_title) {
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

  tcodContext = tcod::new_context(params);
}

void Context::update(tcod::Console &console) { tcodContext->present(console); }

void draw_char(tcod::Console &console, pos_t pos, char icon,
               TCOD_ColorRGBA foreground_color,
               TCOD_ColorRGBA background_color) {
  //
  console.at({pos.x, pos.y}) = {icon, foreground_color, background_color};
}

void blit(tcod::Console &src, tcod::Console &dest) { tcod::blit(dest, src); }

}  