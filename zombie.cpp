#include <string>
#include "zombie.hpp"
#include <iostream>
zombie::zombie(sf::Vector2f size, sf::Vector2f pos, sf::Color c, std::string s) : tile(size, pos, c){
  if (s == "warrior"){
    set_c(sf::Color::Green);
    hp = 30;
    damage = 4;
    mana = 2;
  }
  else if (s == "archer"){
    set_c(sf::Color::White);
    hp = 10;
    damage = 6;
    mana = 4;
  }
  else if (s == "mage"){
    set_c(sf::Color::Yellow);
    hp = 20;
    damage = 2;
    mana = 6;
  }
  else{
    set_c(sf::Color::Cyan);
    hp = 20;
    damage = 4;
    mana = 4;
  }
}
void zombie::moveLeft(int inc){
  if(0 <= get_p().x - inc){
    sf::Vector2f temp = get_p();
    temp.x = get_p().x - inc; 
    set_p(temp);
  }

}
void zombie::moveRight(int ws, int ts, int inc){
  if(ws-ts >= get_p().x + inc){
    sf::Vector2f temp = get_p();
    temp.x = get_p().x +inc;
    set_p(temp);
  }
}
void zombie::moveUp(int inc){
  if(0 <= get_p().y - inc){
    sf::Vector2f temp = get_p();
    temp.y = get_p().y - inc; 
    set_p(temp);
  }

}
void zombie::moveDown(int ws, int ts, int inc){
  if(ws-ts >= get_p().y + inc){
    sf::Vector2f temp = get_p();
    temp.y = get_p().y +inc;
    set_p(temp);
  }
}

void zombie::move(int ws, int ts, int inc, int num){
  if(num==0){
    moveLeft(inc);
  }
  if(num==1){
    moveRight(ws,ts,inc);
  }
  if(num==2){
    moveUp(inc);
  }
  if(num==3){
    moveDown(ws,ts,inc);
  }
}
void zombie::smart_move(sf::Vector2f hp, int ws, int ts, int inc, int ran){
  if(get_p().y > hp.y+4){ // zombie below hero
    if(get_p().x > hp.x+4){ // zombie right of hero
      if(check_move_x(hp) >= check_move_y(hp)){
        moveLeft(inc);
      } else {
        moveUp(inc);
      }
    }
    else{ // zombie left of hero
      if(check_move_x(hp) >= check_move_y(hp)){
        moveRight(ws,ts,inc);
      } else {
        moveUp(inc);
      }
    }
  }
  else{ // zombie above hero
    if(get_p().x > hp.x+4){ // zombie right of hero
      if(check_move_x(hp) >= check_move_y(hp)){
        moveLeft(inc);
      } else {
        moveDown(ws,ts,inc);
      }
    }
    else{ //zombie left of hero
      if(check_move_x(hp) >= check_move_y(hp)){
        moveRight(ws,ts,inc);
      } else {
        moveDown(ws,ts,inc);
      }
    }
  }

}
int zombie::check_move_y(sf::Vector2f hp){
  int re = get_p().y - hp.y; 
  if(re < 0){
    return -re;
  }
  else{
    return re;
  }
}

int zombie::check_move_x(sf::Vector2f hp){
  int re = get_p().x - hp.x; 
  if(re < 0){
    return -re;
  }
  else{
    return re;
  }
}
