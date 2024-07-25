#include "globals.hpp"

Bird::Bird() {
  frames = 4;
  frameDelay = 5;
  reset();
}

void Bird::reset() {
  x = 50;
  y = 5;
  vx = 0;
  vy = 0;
  width = 50;
  height = 50;
  gameOver = false;

  currentFrame = 0;
  tick = 0;
}

void Bird::updateMove() {
  vy += gravity;
  y += vy;
  // std::cout << "Hello" << std::endl;
}

void Bird::update() {
  vy += gravity;
  y += vy;
  if (gameOver) { return; }
  if (y + height >= 400) {
    vy = flap;
    currentScene = Death;
    gameOver = true;
    return;
  }
  if (y + height <= 0) {
    vy = flap;
    currentScene = Death;
    gameOver = true;
    return;
  }
}

void Bird::draw(sf::RenderWindow &window) {
  sf::RectangleShape rectangle1(sf::Vector2f(width, height));
  rectangle1.setPosition(x, y);
  rectangle1.setFillColor(sf::Color(255, 0, 0));
  window.draw(rectangle1);

  birdSprite.setTextureRect(sf::IntRect(currentFrame * 16, 0, 16, 16));
  birdSprite.setPosition(x, y);
  window.draw(birdSprite);
  ++tick;
  if (tick == frameDelay) {
    tick = 0;
    currentFrame = (currentFrame + 1) % frames;
  }
}