#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;
    constexpr float degrees = 2 * M_PI / 180;
    const float circleRadius = 200;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ 1000, 800 }), "Polar Rose",
        sf::Style::Default, settings);

    sf::ConvexShape shape;
    const sf::Vector2f startPosition = {500.f, 400.f};
    shape.setFillColor(sf::Color(0xFF, 0x09, 0x80));
    shape.setPointCount(pointCount);

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

        for (float degree = 1; degree <= 360; degree += 0.5)
        {
            for (int pointNo = 0; pointNo < pointCount; ++pointNo)
            {
                float angle = (2 * M_PI * pointNo) / float(pointCount);
                const float radius = 200 * std::sin(6 * angle);
                sf::Vector2f point = {
                    radius * std::sin(angle),
                    radius * std::cos(angle)
                };

                shape.setPoint(pointNo, point);
            }

            sf::Vector2f offset = {
                circleRadius * std::sin(degree * degrees),
                circleRadius * std::cos(degree * degrees)
            };

            shape.setPosition(startPosition + offset);

            window.clear();
            window.draw(shape);
            window.display();
        }
    }
}