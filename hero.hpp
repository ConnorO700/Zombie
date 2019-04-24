#pragma once
#include "tile.hpp"
#include <string>
class hero : public tile {
public:
  hero(sf::Vector2f size, sf::Vector2f pos, sf::Color c, std::string s);
  void moveLeft(int inc);
  void moveRight(int ws, int ts, int inc);
  void moveUp(int inc);
  void moveDown(int ws, int ts, int inc);
private:
  std::string heroType;
  int hp;
  int damage;
  int mana;
};
