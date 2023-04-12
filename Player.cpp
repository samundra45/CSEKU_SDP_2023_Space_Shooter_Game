#include "Player.h"
#include <iostream>

Player::Player(float x, float y)
    : m_shape(sf::Vector2f(50.0f, 50.0f))
{
    if (!m_sprite.loadFromFile("images/ship.png")) {
        std::cerr << "Failed to load player texture!" << std::endl;
    }
    m_shape.setTexture(&m_sprite);
    m_shape.setTextureRect(sf::IntRect(0, 0, 84, 102));
    m_shape.setPosition(x, y);
    m_speed = 300.0f;
}

void Player::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_shape.move(-m_speed * deltaTime, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_shape.move(m_speed * deltaTime, 0.0f);
    }

}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

sf::FloatRect Player::getGlobalBounds()
{
    return m_shape.getGlobalBounds();
}
