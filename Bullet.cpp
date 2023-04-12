#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float x, float y)
    : m_shape(sf::Vector2f(10.0f, 20.0f))
{
    if (!m_bullets.loadFromFile("images/bullet.png")) {
        std::cerr << "Failed to load bullet texture!" << std::endl;
    }
    m_shape.setTexture(&m_bullets);
    m_shape.setPosition(x, y);
    m_speed = 800.0f;
}

void Bullet::update(float deltaTime)
{
    m_shape.move(0.0f, -m_speed * deltaTime);
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

sf::FloatRect Bullet::getGlobalBounds()
{
    return m_shape.getGlobalBounds();
}
