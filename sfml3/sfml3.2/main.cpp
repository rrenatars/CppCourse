#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

// СДЕЛАЛ ТУТ И SFML3.3

struct EyeBall {
    sf::CircleShape outerCircle;
    sf::CircleShape innerCircle;
    sf::Vector2f position;
    float outerRadius = 80.f;
    float innerRadius = 25.f;
};

struct Eye {
    EyeBall leftEye;
    EyeBall rightEye;
    sf::Vector2f leftEyePosition = {300, 300};
    sf::Vector2f rightEyePosition = {465, 300};
};

void initEyeBall(EyeBall& eyeBall, const sf::Vector2f& position) {
    eyeBall.position = position;
    eyeBall.outerCircle.setRadius(eyeBall.outerRadius);
    eyeBall.outerCircle.setFillColor(sf::Color::White);
    eyeBall.outerCircle.setPosition(eyeBall.position.x - eyeBall.outerRadius, eyeBall.position.y - eyeBall.outerRadius);

    eyeBall.innerCircle.setRadius(eyeBall.innerRadius);
    eyeBall.innerCircle.setFillColor(sf::Color::Black);
    eyeBall.innerCircle.setPosition(eyeBall.position.x - eyeBall.innerRadius, eyeBall.position.y - eyeBall.innerRadius);
}

void initEye(Eye& eye) {
    initEyeBall(eye.leftEye, eye.leftEyePosition);
    initEyeBall(eye.rightEye, eye.rightEyePosition);
}

void updateEyeBall(const sf::Vector2f& mousePosition, EyeBall& eyeBall) {
    const float innerRadius = 27.0f;
    const sf::Vector2f delta = mousePosition - eyeBall.position;
    float angle = std::atan2(delta.y, delta.x);
    sf::Vector2f newPosition = {
        eyeBall.position.x + innerRadius * std::cos(angle),
        eyeBall.position.y + innerRadius * std::sin(angle)
    };
    eyeBall.innerCircle.setPosition(newPosition.x - eyeBall.innerRadius, newPosition.y - eyeBall.innerRadius);
}

void updateEye(const sf::Vector2f& mousePosition, Eye& eye) {
    updateEyeBall(mousePosition, eye.leftEye);
    updateEyeBall(mousePosition, eye.rightEye);
}

void redrawFrame(sf::RenderWindow& window, const Eye& eye) {
    window.clear();
    window.draw(eye.leftEye.outerCircle);
    window.draw(eye.leftEye.innerCircle);
    window.draw(eye.rightEye.outerCircle);
    window.draw(eye.rightEye.innerCircle);
    window.display();
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            mousePosition = {static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)};
            break;
        default:
            break;
        }
    }
}

int main() {
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes follow mouse", sf::Style::Default, settings);

    sf::Vector2f mousePosition;

    Eye eye;
    initEye(eye);

    while (window.isOpen()) {
        pollEvents(window, mousePosition);
        updateEye(mousePosition, eye);
        redrawFrame(window, eye);
    }

    return 0;
}