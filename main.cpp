#include "globals.hpp"

// global variable definitions here

GameScene currentScene = MainGame;

int speed = 2;
float gravity = 0.3f;
float flap = -6.0f;

int score = 0;

Bird bird;
PipesManager pipesManager;

sf::Texture birdTexture;
sf::Texture pipeTexture;
sf::Texture backgroundTexture;
sf::Sprite birdSprite;
sf::Sprite pipeUpSprite;
sf::Sprite pipeDownSprite;
sf::Sprite backgroundSprite;

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 400), "Flappy Bird");
  window.setFramerateLimit(60);

  if (!birdTexture.loadFromFile("img/bird.png")) {
    std::cerr << "Unable to load" << std::endl;
  }
  if (!pipeTexture.loadFromFile("img/pipes.png")) {
    std::cerr << "Unable to load" << std::endl;
  }
  if (!backgroundTexture.loadFromFile("img/background.png")) {
    std::cerr << "Unable to load" << std::endl;
  }
  birdSprite.setTexture(birdTexture);
  birdSprite.setScale(3.125f, 3.125f);
  pipeUpSprite.setTexture(pipeTexture);
  pipeDownSprite.setTexture(pipeTexture);
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(0, 0);
  backgroundSprite.setScale(1.171875f, 1.5625f);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        // std::cout << event.key.scancode << std::endl;
        switch (event.key.scancode) {
          case 40:
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