#include <string>
#include "hero.hpp"
#include <iostream>
hero::hero(sf::Vector2f size, sf::Vector2f pos, sf::Color c, std::string s) : tile(size, pos, c){
  std::cout << "made hero " << std::endl;
  if (s == "warrior"){
    set_c(sf::Color::Red);
    heroType = s;
    hp = 30;
    damage = 4;
    mana = 2;
  }
  else if (s == "archer"){
    set_c(sf::Color::Green);
    heroType = s;
    hp = 10;
    damage = 6;
    mana = 4;
  }
  else if (s == "mage"){
    set_c(sf::Color::Blue);
    heroType = s;
    hp = 20;
    damage = 2;
    mana = 6;
  }
  else{
    set_c(sf::Color::Magenta);
    heroType = s;
    hp = 20;
    damage = 4;
    mana = 4;
  }
}

void hero::moveLeft(int inc){
  if(0 <= get_p().x - inc){
    sf::Vector2f temp = get_p();
    temp.x = get_p().x - inc; 
    set_p(temp);
  }

}
void hero::moveRight(int ws, int ts, int inc){
  if(ws-ts >= get_p().x + inc){
    sf::Vector2f temp = get_p();
    temp.x = get_p().x +inc;
    set_p(temp);
  }
}
void hero::moveUp(int inc){
  if(0 <= get_p().y - inc){
    sf::Vector2f temp = get_p();
    temp.y = get_p().y - inc; 
    set_p(temp);
  }

}
void hero::moveDown(int ws, int ts, int inc){
  if(ws-ts >= get_p().y + inc){
    sf::Vector2f temp = get_p();
    temp.y = get_p().y +inc;
    set_p(temp);
  }
}
