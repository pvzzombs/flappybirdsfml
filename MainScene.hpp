#pragma once

#include "globals.hpp"

void MainScene(sf::RenderWindow &window) {
  window.draw(backgroundSprite);
  if (bird.gameOver) {
    bird.reset();
    pipesManager.reset();
  }
  bird.update();
  pipesManager.update();
  bird.draw(window);
  pipesManager.draw(window);
}