#include <random>
#include <cmath>
#include "globals.hpp"

Pipe::Pipe() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(MIN_PIPE_HEIGHT, MAX_PIPE_HEIGHT);
  
  x = 0;
  y = 0;
  width = 50;
  height = dist(rng);
  hole = PIPE_HOLE_HEIGHT;
  scored = false;
}

bool Pipe::collide() {
  bool up = collided(bird.x, bird.y, bird.width, bird.height,
                    x, y, width, height);
  bool down = collided(bird.x, bird.y, bird.width, bird.height,
                      x, height + hole, width, SCREEN_HEIGHT - height - hole);
  return up || down;
}

bool Pipe::update(float pdt) {
  if (bird.gameOver) { return false; }
  if (bird.x >= x && !scored) {
    scored = true;
    ++score;
    std::cout << score << ", " << height << std::endl;
  }
  if (x + width <= 0) {
    return true;
  }
  x -= speed * pdt;
  return false;
}

void Pipe::draw(sf::RenderWindow &window) {
  int hPipe = height;
  int lPipe = SCREEN_HEIGHT - height - hole;
  sf::RectangleShape rectangle1(sf::Vector2f(width, hPipe));
  sf::RectangleShape rectangle2(sf::Vector2f(width, lPipe));

  rectangle1.setPosition(x, y);
  rectangle1.setFillColor(sf::Color(100, 250, 50));
  window.draw(rectangle1);

  pipeUpSprite.setPosition(x, y);
  pipeUpSprite.setTextureRect(sf::IntRect(0, PIPE_SOURCE_HEIGHT - (hPipe * PIPE_SOURCE_HEIGHT / MAX_PIPE_HEIGHT), 32, std::ceil(hPipe * PIPE_SOURCE_HEIGHT / MAX_PIPE_HEIGHT)));
  window.draw(pipeUpSprite);

  rectangle2.setPosition(x, height + hole);
  rectangle2.setFillColor(sf::Color(100, 250, 50));
  window.draw(rectangle2);

  pipeDownSprite.setPosition(x, height + hole);
  pipeDownSprite.setTextureRect(sf::IntRect(0, 0, 32, lPipe * PIPE_SOURCE_HEIGHT / MAX_PIPE_HEIGHT));
  window.draw(pipeDownSprite);
}

void Pipe::randomizeHeight() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(MIN_PIPE_HEIGHT, MAX_PIPE_HEIGHT);
  height = dist(rng);
}