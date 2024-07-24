#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Bird;
class Pipe;
class PipesManager;

void MainScene(sf::RenderWindow &window);
void DeathScene(sf::RenderWindow &window);

int speed = 2;
float gravity = 0.3f;
float flap = -6.0f;

sf::Texture birdTexture;
sf::Sprite birdSprite;
sf::Texture pipeTexture;
sf::Sprite pipeUpSprite;
sf::Sprite pipeDownSprite;