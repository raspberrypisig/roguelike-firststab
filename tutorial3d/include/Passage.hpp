#pragma once

#include "Position.hpp"

namespace tutorial {

enum class PassageType {
  HORIZONTAL,
  VERTICAL,
  BENT
};

struct Passage {
  pos_t door1;
  pos_t door2;
  PassageType passage_type;
};

}  // namespace tutorial