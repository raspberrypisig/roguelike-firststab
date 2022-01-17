#include "Rectangle.hpp"

namespace tutorial {
Rectangle::Rectangle(pos_t top_left_origin, int width, int height) : top_left(top_left_origin),
                                                                     bottom_right(pos_t{.x = top_left_origin.x + width, .y = top_left_origin.y + height}),
                                                                     width(width),
                                                                     height(height),
                                                                     centre(pos_t{top_left_origin.x + width / 2, top_left_origin.y + height / 2}) {}

}  // namespace tutorial