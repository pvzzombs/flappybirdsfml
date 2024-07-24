#include <iostream>
#include <SFML/Graphics.hpp>

#include "globals.hpp"
#include "scenes.hpp"
#include "bird.hpp"
#include "pipesManager.hpp"
#include "MainScene.hpp"
#include "DeathScene.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 400), "Flappy Bird");
  window.setFramerateLimit(60);

  if (!birdTexture.loadFromFile("img/bird.png")) {
    std::cerr << "Unable to load" << std::endl;
  }
  if (!pipeTexture.loadFromFile("img/pipes.png")) {
    std::cerr << "Unable to load" << std::endl;
  }
  birdSprite.setTexture(birdTexture);
  birdSprite.setScale(3.125f, 3.125f);
  pipeUpSprite.setTexture(pipeTexture);
  pipeDownSprite.setTexture(pipeTexture);

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
      break;
    }
    window.display();
  }
  return 0;
}