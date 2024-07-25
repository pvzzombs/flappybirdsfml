#include <iostream>
#include "globals.hpp"

void RetryScene(sf::RenderWindow &window) {
  // std::cout << "Restart?" << std::endl;
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;
}