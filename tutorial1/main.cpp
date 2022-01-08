#include "Engine.hpp"

int main(int argc, char *argv[]) {
  constexpr int WINDOW_WIDTH = 80;
  constexpr int WINDOW_HEIGHT = 25;
  static const std::string WINDOW_TITLE = "Roguelike libtcod C++ tutorial 1";

  tutorial::Engine engine{WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE};

  while (engine.IsRunning()) {
    engine.Render();
    engine.HandleInput();
  }
}
