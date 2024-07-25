#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

enum GameScene {
  MainMenu,
  MainGame,
  Death,
  Retry
};

class Bird {
public:
  float x, y;
  int width, height;
  float vx, vy;
  int frames;
  int currentFrame;
  bool gameOver;
  int frameDelay;
  int tick;
  Bird();
  void reset();
  void updateMove();
  void update();
  void draw(sf::RenderWindow &window);
};

class Pipe {
public:
  float x, y;
  int width, height;
  int hole;
  bool scored;
  Pipe();
  bool collide();
  bool update();
  void draw(sf::RenderWindow &window);
};

class PipesManager {
public:
  Pipe pipes[3];
  int length;
  void reset();
  PipesManager();
  void update();
  void draw(sf::RenderWindow &window);
};

bool collided(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);

void MainScene(sf::RenderWindow &window);
void DeathScene(sf::RenderWindow &window);
void RetryScene(sf::RenderWindow &window);

extern GameScene currentScene;

extern int speed;
extern float gravity;
extern float flap;

extern int score;

extern Bird bird;
extern PipesManager pipesManager;

extern sf::Texture birdTexture;
extern sf::Texture pipeTexture;
extern sf::Texture backgroundTexture;
extern sf::Sprite birdSprite;
extern sf::Sprite pipeUpSprite;
extern sf::Sprite pipeDownSprite;
extern sf::Sprite backgroundSprite;