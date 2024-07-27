#include "globals.hpp"

void DeathScene(sf::RenderWindow &window) {
  // std::cout << 1 << std::endl;
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;
  bird.updateMove(pdt);
  pipesManager.draw(window);
  bird.draw(window);

  if (bird.y >= SCREEN_HEIGHT) {
    currentScene = Retry;
    return;
  }
}