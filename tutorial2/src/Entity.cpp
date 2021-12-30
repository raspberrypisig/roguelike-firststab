#include "Entity.hpp"

namespace tutorial {

Entity::Entity(pos_t pos, char icon, TCODColor color)
    : pos(pos), icon(icon), color(color) {}

void Entity::SetPos(pos_t pos) { pos = pos; }

pos_t Entity::GetPos() const { return pos; }

void Entity::Render() {}

} // namespace tutorial
