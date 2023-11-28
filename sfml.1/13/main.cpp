#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Picture");

    float x = 300;
    float y = 460;

    window.clear();

    sf::RectangleShape wall;
    wall.setSize({ 600, 330 });
    wall.setPosition({ x, y });
    wall.setFillColor(sf::Color(0x68, 0x02, 0x02));
    window.draw(wall);

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(0xCB, 0x53, 0x53));
    roof.setPosition(600, 320);
    roof.setPointCount(4);
    roof.setPoint(0, {-150, 0});
    roof.setPoint(1, {+150, 0});
    roof.setPoint(2, {+380, 140});
    roof.setPoint(3, {-380, 140});
    window.draw(roof);

    sf::RectangleShape door;
    door.setSize({ 120, 240 });
    door.setPosition({ 460, 790 });
    door.setRotation(180);
    door.setFillColor(sf::Color(0x18, 0x17, 0x17));
    window.draw(door);

    sf::RectangleShape smokePipeVert;
    smokePipeVert.setSize({ 50, 100 });
    smokePipeVert.setPosition({ 730, 400 });
    smokePipeVert.setRotation(180);
    smokePipeVert.setFillColor(sf::Color(0x3B, 0x38, 0x38));
    window.draw(smokePipeVert);

    sf::RectangleShape smokePipeHorizontal;
    smokePipeHorizontal.setSize({ 90, 48 });
    smokePipeHorizontal.setPosition({ 660, 260 });
    smokePipeHorizontal.setFillColor(sf::Color(0x3B, 0x38, 0x38));
    window.draw(smokePipeHorizontal);

    sf::CircleShape smoke1(25);
    smoke1.setPosition({ 700, 225 });
    smoke1.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(smoke1);

    sf::CircleShape smoke2(30);
    smoke2.setPosition({ 715, 185 });
    smoke2.setFillColor(sf::Color(0x6F, 0x6F, 0x6F));
    window.draw(smoke2);

    sf::CircleShape smoke3(35);
    smoke3.setPosition({ 730, 145 });
    smoke3.setFillColor(sf::Color(0x7F, 0x7F, 0x7F));
    window.draw(smoke3);

    sf::CircleShape smoke4(40);
    smoke4.setPosition({ 745, 105 });
    smoke4.setFillColor(sf::Color(0x9F, 0x9F, 0x9F));
    window.draw(smoke4);

    window.display();

    sf::sleep(sf::seconds(15));
}