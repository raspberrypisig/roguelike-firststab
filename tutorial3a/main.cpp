#include "main.hpp"

int main(int argc, char *argv[]) {
  constexpr int WINDOW_WIDTH = 80;
  constexpr int WINDOW_HEIGHT = 25;
  const std::string WINDOW_TITLE = "Roguelike libtcod C++ tutorial 3";
  const std::string font_path = std::filesystem::current_path()
                                    .concat("/../data/Kelora16x16_aa_ro.png")
                                    .generic_string();

  tutorial::Engine engine{WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, font_path};

  while (engine.is_running()) {
    engine.render();
    engine.handle_input();
  }
}
