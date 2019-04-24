#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class tile : public sf::Drawable{
public:
  tile();
  tile(sf::Vector2f size, sf::Vector2f pos, sf::Color);
  void set_p(sf::Vector2f imp); 
  void set_c(sf::Color imp){square.setFillColor(imp);};
  sf::Vector2f get_p(){return square.getPosition();};
  sf::Color get_c(){return square.getFillColor();};
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
  sf::RectangleShape square; 
};
