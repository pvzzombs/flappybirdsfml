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

sf::Font font;
sf::Text text;

int main() {
  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
  window.setFramerateLimit(fps);
  window.setKeyRepeatEnabled(false);

  if (!birdTexture.loadFromFile("resources/img/bird.png")) {
    std::cerr << "Unable to load bird image." << std::endl;
    return 1;
  }
  if (!pipeTexture.loadFromFile("resources/img/pipes.png")) {
    std::cerr << "Unable to load pipes image." << std::endl;
    return 1;
  }
  if (!backgroundTexture.loadFromFile("resources/img/background.png")) {
    std::cerr << "Unable to load background image." << std::endl;
    return 1;
  }

  // load font
  if (!font.loadFromFile("resources/font/ComicMono.ttf")) {
    std::cerr << "Unable to load font." << std::endl;
    return 1;
  }

  birdSprite.setTexture(birdTexture);
  birdSprite.setScale(3.125f, 3.125f);
  pipeUpSprite.setTexture(pipeTexture);
  pipeDownSprite.setTexture(pipeTexture);
  pipeUpSprite.setScale(1.5625f, (float)MAX_PIPE_HEIGHT / PIPE_SOURCE_HEIGHT);
  pipeDownSprite.setScale(1.5625f, (float)MAX_PIPE_HEIGHT / PIPE_SOURCE_HEIGHT);
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(0, 0);
  backgroundSprite.setScale((float)SCREEN_WIDTH / 256.0f, (float)SCREEN_HEIGHT / 256.0f);

  text.setFont(font);
  text.setCharacterSize(20);
  text.setFillColor(sf::Color::Black);
  // text.setOutlineColor(sf::Color::Black);
  text.setPosition(0, 0);

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
                bird.reset();
                pipesManager.reset();
                currentScene = MainGame;
              break;
            }
          break;
        }
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          switch (currentScene) {
            case MainGame:
              bird.vy = flap;
            break;
            case Retry:
              score = 0;
              bird.reset();
              pipesManager.reset();
              currentScene = MainGame;
            break;
          }
        }
      }
    }
    // window.clear(sf::Color::Black);
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