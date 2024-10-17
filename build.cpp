#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"


int main()
{

    //----------------Window creation-----------------//
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Pong", sf::Style::Close);
    
    Paddle player1;
    Paddle player2;
  
    Ball ball;

    //-----------------------Initialize--------------------------//
    
    player1.Initialize(sf::Color::Red, sf::Vector2f(1.6, 250));
    player2.Initialize(sf::Color::Blue, sf::Vector2f(778.4, 250));
    ball.Initialize();
    
    //-----------------------Initialize--------------------------//
    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        
        sf::Keyboard keyboard;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time deltaTime = clock.restart();

        float dt = deltaTime.asSeconds();
    //-----------------Update------------------------------//

        player1.Update(dt, sf::Keyboard::W, sf::Keyboard::S);
        player2.Update(dt, sf::Keyboard::Up, sf::Keyboard::Down);

        ball.Update(dt, player1, player2);
    //----------------Update-------------------------------//

        window.clear(sf::Color::Black);

        player1.Draw(window);
        player2.Draw(window);
        ball.Draw(window);

        window.display();
    }
    //----------------Window creation-----------------//

    return 0;
}