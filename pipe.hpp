#pragma once

#include <random>
#include "globals.hpp"
#include "collision.hpp"
#include "bird.hpp"

class Pipe {
public:
  float x, y;
  int width, height;
  int hole;
  bool scored;
  Pipe() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(50, 200);
    
    x = 0;
    y = 0;
    width = 50;
    height = dist(rng);
    hole = 150;
    scored = false;
  }
  bool collide() {
    bool up = collided(bird.x, bird.y, bird.width, bird.height,
                      x, y, width, height);
    bool down = collided(bird.x, bird.y, bird.width, bird.height,
                        x, height + hole, width, 400 - height - hole);
    return up || down;
  }
  bool update() {
    if (bird.gameOver) { return false; }
    if (bird.x >= x && !scored) {
      scored = true;
    }
    if (x + width <= 0) {
      return true;
    }
    x -= speed;
    return false;
  }
  void draw(sf::RenderWindow &window) {
    int hPipe = height;
    int lPipe = 400 - height - hole;
    sf::RectangleShape rectangle1(sf::Vector2f(width, hPipe));
    sf::RectangleShape rectangle2(sf::Vector2f(width, lPipe));

    rectangle1.setPosition(x, y);
    rectangle1.setFillColor(sf::Color(100, 250, 50));
    window.draw(rectangle1);

    pipeUpSprite.setPosition(x, y);
    pipeUpSprite.setScale(1.5625f, (float)200.f / 80.f);
    pipeUpSprite.setTextureRect(sf::IntRect(0, 80 - (hPipe * 80 / 200), 32, hPipe * 80 / 200));

    rectangle2.setPosition(x, height + hole);
    rectangle2.setFillColor(sf::Color(100, 250, 50));
    window.draw(rectangle2);

    window.draw(pipeUpSprite);
    pipeDownSprite.setPosition(x, height + hole);
    pipeDownSprite.setScale(1.5625f, (float)200.f / 80.f);
    pipeDownSprite.setTextureRect(sf::IntRect(0, 0, 32, lPipe * 80 / 200));
    window.draw(pipeDownSprite);
  }
};