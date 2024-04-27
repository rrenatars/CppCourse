#include <SFML/Graphics.hpp>
#include <iostream>

void drawCat(sf::Sprite &sprite, sf::Texture &texture)
{
    if(!texture.loadFromFile("cat.png"))
    {
        std::cerr << "Failed to load cat.png" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition({ 250, 250 });
}

int main()
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cat Drawing");

    sf::Sprite catSprite;
    sf::Texture catTexture;

    drawCat(catSprite, catTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(catSprite);
        window.display();
    }
}