#include "hero.hpp" 
#include "zombie.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <time.h>
void spawn(int windowSize, sf::Vector2f tileSize, std::vector<zombie> &horde, int amount, std::string s);
int main(){
  int windowSize = 800;
  int tileX = windowSize/100;
  int tileY = windowSize/100;
  sf::Vector2f tileSize(tileX,tileY);
  sf::Vector2f startingPos(windowSize/2,windowSize/2);
  srand (time(NULL));
  std::string userInput; 
  std::cout << "Enter class name: "; 
  std::cin >> userInput; 
  hero h(tileSize, startingPos, sf::Color::Blue, userInput);
  bool proj = false;
  zombie m(tileSize,startingPos, sf::Color::Green, userInput);
  std::vector<zombie> horde; 
  sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(windowSize,windowSize), "Map");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    int inc = 5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      h.moveLeft(inc);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
      h.moveRight(windowSize, tileX, inc);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      h.moveUp(inc);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      h.moveDown(windowSize, tileY, inc);
    }
    
      sf::Vector2i mousep = sf::Mouse::getPosition(window); 
      sf::Vector2f position1(mousep.x-15,mousep.y-15);
      sf::CircleShape aimerOuter(15);
      aimerOuter.setFillColor(sf::Color::Black);
      aimerOuter.setPosition(position1);
      aimerOuter.setOutlineThickness(2);
      aimerOuter.setOutlineColor(h.get_c());
      window.draw(aimerOuter);

      sf::Vector2f position2(mousep.x-9,mousep.y-9);
      sf::CircleShape aimerInner(9);
      aimerInner.setFillColor(sf::Color::Black);
      aimerInner.setPosition(position2);
      aimerInner.setOutlineThickness(2);
      aimerInner.setOutlineColor(h.get_c());
      window.draw(aimerInner);

      sf::Vector2f position3(mousep.x-3,mousep.y-3);
      sf::CircleShape aimerDot(3);
      aimerDot.setFillColor(sf::Color::Black);
      aimerDot.setPosition(position3);
      aimerDot.setOutlineThickness(2);
      aimerDot.setOutlineColor(h.get_c());
      window.draw(aimerDot);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      //projectile laser();
      //projectile.setPosition(h.get_p());
      //sf::RectangleShape projectile(sf::Vector2f(1,));
    }
    if(proj){
      //sf::RectangleShape projectile(sf::Vector2f(1,5));
      //window.draw(projectile); 
    }

    sf::Time elapsed = clock.getElapsedTime();
    if((int)elapsed.asSeconds() % 2 == 0){
      spawn(windowSize,tileSize,horde,2, userInput);
    }
    for(unsigned int i = 0; i < horde.size();i++){
      int moveType = rand() % 100;
      if(moveType < 20){
        int ran = rand() % 2;
        horde[i].smart_move(h.get_p(),windowSize,tileX,inc-2, ran);
      }
      else{
        int ran = rand() % 4;
        horde[i].move(windowSize,tileX,inc-2, ran);
      }
    }


    sf::sleep(sf::milliseconds(50)); 
    for(unsigned int i = 0; i < horde.size();i++){
      window.draw(horde[i]);
    }
    window.draw(h);
    window.display();
  }

}

void spawn(int windowSize, sf::Vector2f tileSize, std::vector<zombie> &horde, int amount, std::string userInput){
  
  for(int i =0; i < amount; i++){
    int side = rand() % 4;
    int ranNum = rand() % windowSize-tileSize.x;
    if(side == 0){ //left
      sf::Vector2f temp(0,ranNum);
      
      zombie z(tileSize,temp, sf::Color::Green, userInput);
      horde.push_back(z);
    }
    else if(side == 1){ //right
      sf::Vector2f temp(windowSize - tileSize.x,ranNum);
      
      zombie z(tileSize,temp, sf::Color::Green, userInput);
      horde.push_back(z);
    }
    else if(side == 2){ //top
      sf::Vector2f temp(ranNum,0);
      
      zombie z(tileSize,temp, sf::Color::Green, userInput);
      horde.push_back(z);
    }
    else if(side == 3){ //bottom
      sf::Vector2f temp(ranNum,windowSize-tileSize.y);
      
      zombie z(tileSize,temp, sf::Color::Green, userInput);
      horde.push_back(z);
    }
  }
}


