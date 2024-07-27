#include <iostream>
#include <string>
#include "globals.hpp"

void RetryScene(sf::RenderWindow &window) {
  // std::cout << "Restart?" << std::endl;
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;

  window.draw(backgroundSprite);

  text.setString("Score: " + std::to_string(score));
  text.setPosition((SCREEN_WIDTH / 2) - (text.getGlobalBounds().width / 2), 20);
  window.draw(text);
  text.setString("Press space to retry");
  text.setPosition((SCREEN_WIDTH / 2) - (text.getGlobalBounds().width / 2), 40);
  window.draw(text);
}