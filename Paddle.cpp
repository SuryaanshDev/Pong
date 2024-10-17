#include "Paddle.h"

Paddle::Paddle() :

    paddleSpeed(400.0f), width(20.0f), height(100.0f)
{
}

Paddle::~Paddle()
{
}

void Paddle::Initialize(sf::Color color, sf::Vector2f Position)
{
    paddle.setSize(sf::Vector2f(width, height));
	paddle.setFillColor(color);
    paddle.setPosition(Position);
    paddle.setOutlineThickness(1);
    paddle.setOutlineColor(sf::Color::Black);
}

void Paddle::Update(float dt, sf::Keyboard::Key up, sf::Keyboard::Key down) {

    sf::Vector2f position = paddle.getPosition();


    if (sf::Keyboard::isKeyPressed(down)) {

        if (position.y + paddle.getSize().y < 600.0f) {

            paddle.move(0.0f, paddleSpeed * dt);
        }
    }

    if (sf::Keyboard::isKeyPressed(up)) {

        if (position.y > 0.0) {

            paddle.move(0.0f, -paddleSpeed * dt);
        }
    }
}

void Paddle::Draw(sf::RenderWindow &window)
{

    window.draw(paddle);
}

float Paddle::getPaddleX()
{
    return paddle.getPosition().x;
}

float Paddle::getPaddleY()
{
    return paddle.getPosition().y;
}

float Paddle::getWidth()
{
    return width;
}

float Paddle::getHeight()
{
    return height;
}

