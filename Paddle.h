#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
public :

	sf::RectangleShape paddle;
private :

	float width = 20.0f;
	float height = 100.0f;
	float paddleSpeed = 400.0f;

public :

	Paddle();
	~Paddle();
	void Initialize(sf::Color color, sf::Vector2f Position);
	void Update(float dt, sf::Keyboard::Key up, sf::Keyboard::Key down);
	void Draw(sf::RenderWindow &window);

	float getPaddleX();
	float getPaddleY();
	float getWidth();
	float getHeight();
};

