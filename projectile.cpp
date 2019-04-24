#include "projectile.hpp"

projectile::projectile(sf::Vector2f i, sf::Vector2f t){
  beam.setPointCount(3);
  beam.setPoint(0,i);
  beam.setPoint(1,sf::Vector2f(t.x+2,t.y+2));
  beam.setPoint(2,sf::Vector2f(t.x-2,t.y-2));

}

void tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(beam);

}
