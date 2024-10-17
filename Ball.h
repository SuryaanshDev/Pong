#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
private :

	sf::CircleShape ball;

	sf::Vector2f ballSpeed;
	float radius;

public :

	Ball();
	~Ball();
	void Initialize();
	void Update(float deltaTime, Paddle& paddle1, Paddle& paddle2);
	void Draw(sf::RenderWindow &window);
};

