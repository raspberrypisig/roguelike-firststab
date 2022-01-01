#pragma once

#include <SDL2/SDL.h>
#include <libtcod.hpp>

namespace tutorial {

class Context {
public:
  Context() = delete;
  Context(tcod::Console &console, const std::string &window_title);
  tcod::ContextPtr create_new_context();

private:
  TCOD_ContextParams params;
};

} // namespace tutorial
