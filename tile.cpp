#include "tile.hpp"
#include <iostream>
//################## CONSTRUCTOR
//	@param Vector2f size - draw size of tile
//	@param int x, y - tile coordinates
//	@param sf:Color c - color of tile
//##################
tile::tile(){
  square.setFillColor(sf::Color::Red);
  square.setPosition(0,0);
  square.setSize(sf::Vector2f(10,10));
}
tile::tile(sf::Vector2f size, sf::Vector2f pos, sf::Color c){
  square.setFillColor(c); 
  square.setPosition(pos); 
  square.setSize(size); 
}
//##################
//	@param RenderTarget - draws a class variable sf::RectangleShape
//##################
void tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(square);

}



void tile::set_p(sf::Vector2f imp){
  square.setPosition(imp);
}


