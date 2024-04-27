#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

struct Pointer
{
    sf::Sprite sprite;
    sf::Vector2f position; 
    bool isClicked = false;
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

float toRadians(float degrees)
{
    return float(double(degrees) * M_PI / 180.0);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void onMouseClick(const sf::Event::MouseButtonEvent &event, Pointer &pointer)
{
    if (event.button == sf::Mouse::Left)
    {
        pointer.sprite.setPosition({float(event.x), float(event.y)});
        pointer.position = {float(event.x), float(event.y)};
        pointer.isClicked = true;
    }
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, Pointer &pointer)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, pointer);
            break;
        default:
            break;
        }
    }
}

void updateCat(sf::Sprite &cat, const sf::Vector2f &mousePosition, const Pointer &pointer)
{
    if (pointer.isClicked)
    {
        float angle = std::atan2(pointer.position.y - cat.getPosition().y, pointer.position.x - cat.getPosition().x);
        float degrees = toDegrees(angle);

        if (degrees < 0)
        {
            degrees += 360.0f;
        }

        if (degrees >= 90.0f && degrees <= 270.0f)
        {
            cat.setScale(-1.0f, 1.0f);
        }
        else
        {
            cat.setScale(1.0f, 1.0f);
        }

        float distance = std::sqrt(std::pow(pointer.position.x - cat.getPosition().x, 2) + std::pow(pointer.position.y - cat.getPosition().y, 2));
        float speed = 1.0f;
        float deltaTime = 1.0f / 60.0f;
        float dx = speed * std::cos(toRadians(degrees)) * deltaTime;
        float dy = speed * std::sin(toRadians(degrees)) * deltaTime;

        if (distance > 10.0f)
        {
            cat.move(dx, dy);
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::Sprite &cat, Pointer &pointer)
{
    window.clear(sf::Color::White);
    if (pointer.isClicked)
    {
        window.draw(pointer.sprite);
    }
    window.draw(cat);
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cat Drawing");

    sf::Texture catTexture;
    if (!catTexture.loadFromFile("cat.png"))
    {
        std::cerr << "Failed to load cat.png" << std::endl;
        return 1;
    }
    sf::Sprite cat(catTexture);
    cat.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    sf::Texture pointerTexture;
    if (!pointerTexture.loadFromFile("red_pointer.png"))
    {
        std::cerr << "Failed to load red_pointer.png" << std::endl;
        return 1;
    }
    Pointer pointer;
    pointer.sprite.setTexture(pointerTexture);
    pointer.sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition, pointer);
        updateCat(cat, mousePosition, pointer);
        redrawFrame(window, cat, pointer);
    }

    return 0;
}