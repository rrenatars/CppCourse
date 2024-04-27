#include <SFML/Graphics.hpp>
#include <cmath>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
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
            default:
                break;
        }
    }
}

// Обновляет фигуру, указывающую на мышь
void update(const sf::Vector2f& mousePosition, sf::ConvexShape& arrow, sf::Clock& clock)
{
    const float maxSpeed = 20.f; // Максимальная скорость движения стрелки (пикселей в секунду)
    const float maxRotationSpeed = 90.f; // Максимальная скорость поворота стрелки (градусов в секунду)

    const sf::Vector2f arrowPosition = arrow.getPosition();
    const sf::Vector2f motion = mousePosition - arrowPosition;
    const float distance = std::sqrt(motion.x * motion.x + motion.y * motion.y);

    if (distance > 0.f)
    {
        const float deltaTime = clock.restart().asSeconds();
        const sf::Vector2f direction =
        {
            (motion.x / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))),
            (motion.y / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y)))
        };
        const float speed = std::min(distance / deltaTime, maxSpeed);
        const float angle = std::atan2(direction.y, direction.x);
        const float rotation = toDegrees(angle) - arrow.getRotation();
        const float rotationSpeed = std::min(std::abs(rotation) / deltaTime, maxRotationSpeed);

        arrow.move(direction.x * speed * deltaTime, direction.y * speed * deltaTime);
        arrow.rotate(rotation + 265.f);
    }
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color::White);
    window.draw(arrow);
    window.display();
}

void createArrow(sf::ConvexShape &arrow)
{
    arrow.setPointCount(7);
    arrow.setPoint(0, {0,0});
    arrow.setPoint(1, {0,60});
    arrow.setPoint(2, {30,60});
    arrow.setPoint(3, {-30,120 });
    arrow.setPoint(4, {-90,60});
    arrow.setPoint(5, {-60, 60});
    arrow.setPoint(6, {-60, 0});

    arrow.setPosition({200, 200});
    arrow.setFillColor(sf::Color::Yellow);
    arrow.setOutlineColor(sf::Color::Black);
    arrow.setOutlineThickness(2);
    arrow.setRotation(195);
}

int main()
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arrow Drawing", sf::Style::Default);
    sf::ConvexShape arrow;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    createArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock);
        redrawFrame(window, arrow);
    }
}