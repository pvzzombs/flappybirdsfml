#include <random>
#include "globals.hpp"

PipesManager::PipesManager() {
  length = 3;
  reset();
}

void PipesManager::reset() {
  int pipeStartX = 0;
  for (int i = 0; i < length; i++) {
    pipes[i] = Pipe();
    pipes[i].x = pipeStartX + 350;
    pipeStartX += 200;
  }
}

void PipesManager::update(float pdt) {
  bool isOutOfBounds;
  for (int i = 0; i < length; i++) {
    if (i == 0) {
      isOutOfBounds = pipes[i].update(pdt);
    } else {
      pipes[i].update(pdt);
    }
    if (pipes[i].collide()) {
      bird.vy = flap;
      currentScene = Death;
      bird.gameOver = true;
      return;
    }
  }
  float lastPipeX = pipes[length - 1].x;

  if (isOutOfBounds) {
    Pipe temp = pipes[0];
    for (int i = 1; i < length; i++) {
      pipes[i - 1] = pipes[i];
    }
    pipes[length - 1] = temp;

    pipes[length - 1].x = lastPipeX + 200;
    pipes[length - 1].randomizeHeight();
    pipes[length - 1].scored = false;
  }
}

void PipesManager::draw(sf::RenderWindow &window) {
  for (int i = 0; i < length; i++) {
    pipes[i].draw(window);
  }
}