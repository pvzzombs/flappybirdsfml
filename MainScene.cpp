#include "globals.hpp"

void MainScene(sf::RenderWindow &window) {
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;
  // std::cout << pdt << std::endl;
  window.draw(backgroundSprite);
  if (bird.gameOver) {
    bird.reset();
    pipesManager.reset();
  }
  bird.update(pdt);
  pipesManager.update(pdt);
  pipesManager.draw(window);
  bird.draw(window);
}