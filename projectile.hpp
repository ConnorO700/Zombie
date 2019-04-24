#pragma once
#include <SFML/Graphics.hpp>
class projectile : public sf::Drawable{
public:
  projectile(sf::Vector2f initial, sf::Vector2f target);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
  sf::ConvexShape beam;
};
