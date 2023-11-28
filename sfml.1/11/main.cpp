#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 110, 320 }), "Lighter", sf::Style::None);

    window.clear();

    sf::CircleShape greenShape(40);
    greenShape.setPosition({ 15, 20 });
    greenShape.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(greenShape);

    sf::CircleShape yellowShape(40);
    yellowShape.setPosition({ 15, 120 });
    yellowShape.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(yellowShape);

    sf::CircleShape redShape(40);
    redShape.setPosition({ 15, 220 });
    redShape.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(redShape);

    window.display();

    sf::sleep(sf::seconds(15));
}