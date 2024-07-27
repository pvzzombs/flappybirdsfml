#include <string>
#include "globals.hpp"

void MainScene(sf::RenderWindow &window) {
  sf::Time dt = deltaClock.restart();
  float pdt = dt.asSeconds() * (float)fps;
  // std::cout << pdt << std::endl;
  if (bird.gameOver) {
    bird.reset();
    pipesManager.reset();
  }
  bird.update(pdt);
  pipesManager.update(pdt);
  text.setString("Score: " + std::to_string(score));
  text.setPosition(0, 0);

  window.draw(backgroundSprite);
  pipesManager.draw(window);
  bird.draw(window);
  window.draw(text);
}