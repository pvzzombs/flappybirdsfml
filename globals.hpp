#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 400
#define MIN_PIPE_HEIGHT 50
#define PIPE_HOLE_HEIGHT 150
#define MAX_PIPE_HEIGHT (SCREEN_HEIGHT - MIN_PIPE_HEIGHT - PIPE_HOLE_HEIGHT)
#define PIPE_SOURCE_HEIGHT 160.0f

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
  void updateMove(float pdt);
  void update(float pdt);
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
  bool update(float pdt);
  void draw(sf::RenderWindow &window);
  void randomizeHeight();
};

class PipesManager {
public:
  Pipe pipes[3];
  int length;
  void reset();
  PipesManager();
  void update(float pdt);
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

extern int fps;
extern int score;

extern Bird bird;
extern PipesManager pipesManager;

extern sf::Clock deltaClock;

extern sf::Texture birdTexture;
extern sf::Texture pipeTexture;
extern sf::Texture backgroundTexture;
extern sf::Sprite birdSprite;
extern sf::Sprite pipeUpSprite;
extern sf::Sprite pipeDownSprite;
extern sf::Sprite backgroundSprite;