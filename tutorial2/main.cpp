#include "Engine.hpp"

int main(int argc, char *argv[]) {
  constexpr int WINDOW_WIDTH = 80;
  constexpr int WINDOW_HEIGHT = 25;
  const std::string WINDOW_TITLE = "libtcod C++ tutorial 2";

  tutorial::Engine engine{WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE};

  while (engine.is_running()) {
    engine.render();
    engine.handle_input();
  }
}
