#include "globals.hpp"

// global variable definitions here

GameScene currentScene = MainGame;

int speed = 2;
float gravity = 0.3f;
float flap = -6.0f;

int fps = 60;
int score = 0;

Bird bird;
PipesManager pipesManager;

sf::Clock deltaClock;

sf::Texture birdTexture;
sf::Texture pipeTexture;
sf::Texture backgroundTexture;
sf::Sprite birdSprite;
sf::Sprite pipeUpSprite;
sf::Sprite pipeDownSprite;
sf::Sprite backgroundSprite;

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 400), "Flappy Bird");
  window.setFramerateLimit(fps);
  window.setKeyRepeatEnabled(false);

  if (!birdTexture.loadFromFile("img/bird.png")) {
    std::cerr << "Unable to load bird image." << std::endl;
  }
  if (!pipeTexture.loadFromFile("img/pipes.png")) {
    std::cerr << "Unable to load pipes image." << std::endl;
  }
  if (!backgroundTexture.loadFromFile("img/background.png")) {
    std::cerr << "Unable to load background image." << std::endl;
  }
  birdSprite.setTexture(birdTexture);
  birdSprite.setScale(3.125f, 3.125f);
  pipeUpSprite.setTexture(pipeTexture);
  pipeDownSprite.setTexture(pipeTexture);
  pipeUpSprite.setScale(1.5625f, 200.f / 80.f);
  pipeDownSprite.setScale(1.5625f, 200.f / 80.f);
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(0, 0);
  backgroundSprite.setScale(1.171875f, 1.5625f);

  deltaClock.restart();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        // std::cout << event.key.scancode << std::endl;
        switch (event.key.scancode) {
          case sf::Keyboard::Scan::Space:
            switch (currentScene) {
              case MainGame:
                bird.vy = flap;
              break;
              case Retry:
                score = 0;
                currentScene = MainGame;
              break;
            }
          break;
        }
      }
    }
    window.clear(sf::Color::Black);
    switch (currentScene) {
      case MainMenu:
      break;
      case MainGame:
        MainScene(window);
      break;
      case Death:
        DeathScene(window);
      break;
      case Retry:
        RetryScene(window);
      break;
    }
    window.display();
  }
  return 0;
}