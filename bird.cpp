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
  width = BIRD_WIDTH;
  height = BIRD_HEIGHT;
  gameOver = false;

  currentFrame = 0;
  tick = 0;

  angle = 0.0f;
}

void Bird::updateMove(float pdt) {
  vy += gravity * pdt;
  y += vy * pdt;
  // std::cout << "Hello" << std::endl;
}

void Bird::update(float pdt) {
  vy += gravity * pdt;
  y += vy * pdt;
  if (gameOver) { return; }
  if (y + height >= SCREEN_HEIGHT) {
    vy = flap;
    // angle = 45.0f;
    currentScene = Death;
    gameOver = true;
    return;
  }
  if (y + height <= 0) {
    vy = flap;
    // angle = 45.0f;
    currentScene = Death;
    gameOver = true;
    return;
  }
}

void Bird::draw(sf::RenderWindow &window) {
  // sf::FloatRect birdBoundingBox = birdSprite.getGlobalBounds();
  // sf::RectangleShape rectangle1(birdBoundingBox.getSize());
  // rectangle1.setPosition(birdBoundingBox.getPosition());
  // rectangle1.setFillColor(sf::Color(255, 0, 0));
  // window.draw(rectangle1);

  // sf::FloatRect birdBoundingBox2(sf::Vector2f(x, y), sf::Vector2f(width, height));
  // sf::RectangleShape rectangle2(birdBoundingBox2.getSize());
  // rectangle2.setPosition(birdBoundingBox2.getPosition());
  // rectangle2.setFillColor(sf::Color(0, 255, 0));
  // window.draw(rectangle2);

  // sf::RectangleShape center(sf::Vector2f(1.0f, 1.0f));
  // center.setPosition(x + width / 2, y + height / 2);
  // center.setFillColor(sf::Color::Black);

  birdSprite.setTextureRect(sf::IntRect(currentFrame * BIRD_SOURCE_WIDTH, 0, BIRD_SOURCE_WIDTH, BIRD_SOURCE_HEIGHT));
  birdSprite.setOrigin((float)BIRD_SOURCE_WIDTH / 2, (float)BIRD_SOURCE_HEIGHT / 2);
  birdSprite.setRotation(angle);
  if (angle < 90.0f && vy >= 0.0f) {
    angle += 4.5f;
  }
  birdSprite.setPosition(x + (float)BIRD_WIDTH / 2, y + (float)BIRD_HEIGHT / 2);
  window.draw(birdSprite);
  // window.draw(center);
  ++tick;
  if (tick == frameDelay) {
    tick = 0;
    currentFrame = (currentFrame + 1) % frames;
  }
}