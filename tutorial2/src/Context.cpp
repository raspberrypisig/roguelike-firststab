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

  tcodContext = tcod::new_context(params);
}

void Context::update(tcod::Console &console) { tcodContext->present(console); }

std::vector<tcod::ConsolePtr>
new_console_from_rexpaint(const std::string &path) {
  auto consoles = tcod::load_xp(path);
  return consoles;
}
void draw_entity(tcod::Console &console, pos_t pos, char icon,
                 TCOD_ColorRGB color) {
  constexpr auto background_color = TCOD_ColorRGBA{0, 0, 0, 255};
  auto foreground_color = TCOD_ColorRGBA{color.r, color.g, color.b, 255};

  console.at({pos.x, pos.y}) = {icon, foreground_color, background_color};
}

void blit(tcod::Console &src, tcod::Console &dest) {
  // blit
  tcod::blit(dest, src);
}

} // namespace tutorial