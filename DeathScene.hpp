#pragma once
#include <iostream>

void DeathScene(sf::RenderWindow &window) {
  // std::cout << 1 << std::endl;
  bird.updateMove();
  pipesManager.draw(window);
  bird.draw(window);

  if (bird.y >= 400) {
    currentScene = Retry;
    return;
  }
}