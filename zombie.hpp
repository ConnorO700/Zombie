#pragma once
#include "tile.hpp"
#include <string>
class zombie : public tile {
public:
  zombie(sf::Vector2f size, sf::Vector2f pos, sf::Color c, std::string s);
  void smart_move(sf::Vector2f hp,int ws, int ts, int inc, int ran);
  int check_move_x(sf::Vector2f hp);
  int check_move_y(sf::Vector2f hp);
  void move(int ws, int ts, int inc, int ran);
  void moveLeft(int inc);
  void moveRight(int ws, int ts, int inc);
  void moveUp(int inc);
  void moveDown(int ws, int ts, int inc);
private:
  int hp;
  int damage;
  int mana;
};
