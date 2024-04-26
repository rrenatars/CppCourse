#include <SFML/Graphics.hpp>

void createArrow(sf::ConvexShape &pointer)
{
    pointer.setPointCount(7);
    pointer.setPoint(0, {0,0});
    pointer.setPoint(1, {0,60});
    pointer.setPoint(2, {30,60});
    pointer.setPoint(3, {-30,120 });
    pointer.setPoint(4, {-90,60});
    pointer.setPoint(5, {-60, 60});
    pointer.setPoint(6, {-60, 0});

    pointer.setPosition({200, 200});
    pointer.setFillColor(sf::Color::Yellow);
    pointer.setOutlineColor(sf::Color::Black);
    pointer.setOutlineThickness(2);
    pointer.setRotation(195);
}

int main()
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arrow Drawing", sf::Style::Default);
    sf::ConvexShape arrow;

    createArrow(arrow);
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

        window.clear(sf::Color::White);
        window.draw(arrow);
        window.display();
    }
}