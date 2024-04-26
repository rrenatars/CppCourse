#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Wave Moving Ball");
    sf::Clock clock;
    sf::Clock clock2;

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    float speedX = 100.f;

    const sf::Vector2f startPos = {10, 300};

    ball.setPosition(startPos);
    sf::Vector2f curPos = ball.getPosition();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float time = clock.getElapsedTime().asSeconds();
        const float dTime = clock2.restart().asSeconds();
        const float wavePhase = time * float(2 * M_PI);
        curPos.x += speedX * dTime;
        curPos.y = 300 + amplitudeY * std::sin(wavePhase / periodY);

        if (((curPos.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0)) || ((curPos.x <= 0) && (speedX < 0))) {
            speedX = -speedX;
        }
 
        ball.setPosition(curPos);

        window.clear();
        window.draw(ball);
        window.display();
    }
}