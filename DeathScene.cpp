#include "globals.hpp"

void DeathScene(sf::RenderWindow &window) {
  // std::cout << 1 << std::endl;
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;
  bird.updateMove(pdt);

  if (bird.y >= SCREEN_HEIGHT) {
    currentScene = Retry;
    return;
  }

  window.draw(backgroundSprite);
  pipesManager.draw(window);
  bird.draw(window);
}