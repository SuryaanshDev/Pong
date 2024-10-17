#include "Ball.h"

Ball::Ball() :
	ballSpeed(300.0f, 300.0f), radius(10.0f)
{
}

Ball::~Ball()
{
}

void Ball::Initialize()
{

	ball.setRadius(radius);
	ball.setFillColor(sf::Color::Yellow);
	ball.setOutlineThickness(1);
	ball.setOutlineColor(sf::Color::Black);
	ball.setPosition(sf::Vector2f(400, 300));
}

void Ball::Update(float deltaTime, Paddle& paddle1, Paddle& paddle2)
{

	sf::Vector2f movement = ballSpeed * deltaTime;
	ball.move(movement);

	float ballX = ball.getPosition().x;
	float ballY = ball.getPosition().y;
	float ballRadius = ball.getRadius();

	float paddleX1 = paddle1.getPaddleX();
	float paddleY1 = paddle1.getPaddleY();
	float paddleWidth1 = paddle1.getWidth();
	float paddleHeight1 = paddle1.getHeight();

	float paddleX2 = paddle2.getPaddleX();
	float paddleY2 = paddle2.getPaddleY();
	float paddleWidth2 = paddle2.getWidth();
	float paddleHeight2 = paddle2.getHeight();

	if (ballY < 0 || ballY + ball.getRadius() * 2 > 600) {

		ballSpeed.y = -ballSpeed.y;
	}
	
	if (ballX < 0 || ballX + ball.getRadius() * 2 > 1000) {
		
		ball.setPosition(400, 300);
		
	}

	// Paddle1 collision (Left paddle) 
	if (ballX - ballRadius < paddleX1 + paddleWidth1) {

		ballSpeed.x = -ballSpeed.x;
	}
	// Paddle2 collision (Right paddle)
	if (ballX + ballRadius > paddleX2) {

		ballSpeed.x = -ballSpeed.x;
	}

}

void Ball::Draw(sf::RenderWindow &window)
{

	window.draw(ball);
}