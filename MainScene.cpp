#include "globals.hpp"

void MainScene(sf::RenderWindow &window) {
  window.draw(backgroundSprite);
  if (bird.gameOver) {
    bird.reset();
    pipesManager.reset();
  }
  bird.update();
  pipesManager.update();
  pipesManager.draw(window);
  bird.draw(window);
}