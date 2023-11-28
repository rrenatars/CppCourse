#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <cmath>

void drawA(sf::RenderWindow& window, float& x, float& y){

    float lineWidth = 15;
    float lineHeight = 100;
    float diagonalLength = 100;
    int rotation = 60;

    sf::RectangleShape diagonalLine;
    diagonalLine.setSize({ diagonalLength, lineWidth });
    diagonalLine.setRotation(180 - rotation);
    diagonalLine.setPosition({ x, y });
    diagonalLine.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(diagonalLine);

    sf::RectangleShape line;
    line.setSize({ 80, lineWidth });
    line.setRotation(180);
    x = x + sin(rotation * M_PI / 180.0) * diagonalLength - lineWidth * 2.4;
    y = y + cos(rotation * M_PI / 180.0) * diagonalLength;
    line.setPosition({ x, y });
    line.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(line);

    x = 275;
    y = 165;
    rotation = 119;

    diagonalLine.setRotation(180 - rotation);
    diagonalLine.setPosition({ x, y });
    window.draw(diagonalLine);

    x = 275;
    y = 180;

    line.setSize({ 37, lineWidth });
    line.setPosition({ x, y });
    window.draw(line);
}

void drawR(sf::RenderWindow& window, float& x, float& y){

    float lineWidth = 15;
    float lineHeight = 80;

    sf::RectangleShape verticalLine;
    verticalLine.setSize({ lineHeight, lineWidth });
    verticalLine.setRotation(90);
    verticalLine.setPosition({ x, y });
    verticalLine.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(verticalLine);

    sf::RectangleShape line;
    line.setSize({ 75, lineWidth });
    line.setRotation(180);
    line.setPosition({ x + 60, y });
    line.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(line);

    verticalLine.setSize({ 40, lineWidth });
    verticalLine.setPosition({ x + 60, y });
    window.draw(verticalLine);

    line.setSize({ 75, lineWidth });
    line.setPosition({ x + 60, y + 40 });
    window.draw(line);

    float diagonalLength = 70;
    int rotation = 50;

    sf::RectangleShape diagonalLine;
    diagonalLine.setSize({ diagonalLength, lineWidth });
    diagonalLine.setRotation(90 - rotation);
    diagonalLine.setPosition({ x + 10, y + 25 });
    diagonalLine.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(diagonalLine);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Initials");

    float x = 250;
    float y = 175;

    window.clear();

    drawA(window, x, y);
    x += 80;
    drawR(window, x, y);
    x += 100;
    drawR(window, x, y);

    window.display();

    sf::sleep(sf::seconds(15));
}