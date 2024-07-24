#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Bird;
class Pipe;
class PipesManager;

void MainScene(sf::RenderWindow &window);
void DeathScene(sf::RenderWindow &window);
void RetryScene(sf::RenderWindow &window);

int speed = 2;
float gravity = 0.3f;
float flap = -6.0f;

int score = 0;

sf::Texture birdTexture;
sf::Texture pipeTexture;
sf::Texture backgroundTexture;
sf::Sprite birdSprite;
sf::Sprite pipeUpSprite;
sf::Sprite pipeDownSprite;
sf::Sprite backgroundSprite;