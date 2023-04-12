#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float x, float y, const sf::Texture& texture)
    : m_shape(sf::Vector2f(50.0f, 50.0f)), m_texture(&texture)
{
  
    m_shape.setTexture(m_texture);
    m_shape.setPosition(x, y);
    m_speed = 100.0f;
}

void Enemy::update(float deltaTime)
{
    m_shape.move(0.0f, m_speed * deltaTime);
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

sf::FloatRect Enemy::getGlobalBounds() 
{
    return m_shape.getGlobalBounds();
}
