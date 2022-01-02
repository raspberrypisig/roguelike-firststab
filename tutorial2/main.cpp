#include "main.hpp"
#include "Engine.hpp"

int main(int argc, char *argv[]) {
  constexpr int WINDOW_WIDTH = 80;
  constexpr int WINDOW_HEIGHT = 25;
  const std::string WINDOW_TITLE = "Roguelike libtcod C++ tutorial 2a";
  auto rexpaint_file_path = std::filesystem::current_path()
                                .concat("/../data/rexpaint_tutorial2a.xp")
                                .generic_string();

  tutorial::Engine engine{WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE,
                          rexpaint_file_path};

  while (engine.is_running()) {
    engine.render();
    engine.handle_input();
  }
}
