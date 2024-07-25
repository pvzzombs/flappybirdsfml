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

void PipesManager::update() {
  bool isOutOfBounds;
  for (int i = 0; i < length; i++) {
    if (i == 0) {
      isOutOfBounds = pipes[i].update();
    } else {
      pipes[i].update();
    }
    if (pipes[i].collide()) {
      bird.vy = flap;
      currentScene = Death;
      bird.gameOver = true;
      return;
    }
  }
  float lastPipeX = pipes[length - 1].x;
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(50, 200);

  if (isOutOfBounds) {
    Pipe temp = pipes[0];
    for (int i = 1; i < length; i++) {
      pipes[i - 1] = pipes[i];
    }
    pipes[length - 1] = temp;

    pipes[length - 1].x = lastPipeX + 200;
    pipes[length - 1].height = dist(rng);
    pipes[length - 1].scored = false;
  }
}

void PipesManager::draw(sf::RenderWindow &window) {
  for (int i = 0; i < length; i++) {
    pipes[i].draw(window);
  }
}