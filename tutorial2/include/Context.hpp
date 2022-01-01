#pragma once

#include <SDL2/SDL.h>
#include <libtcod.hpp>

namespace tutorial {

class Context {
public:
  Context() = default;
  Context(tcod::Console &console, const std::string &window_title);

private:
  TCOD_ContextParams params;
  tcod::ContextPtr tcodContext;
};

} // namespace tutorial
