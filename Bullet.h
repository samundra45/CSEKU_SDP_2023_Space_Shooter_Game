#pragma once
#include <SFML/Graphics.hpp>

class Bullet {


public:
    Bullet(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();

    bool operator==(const Bullet& other) const
    {
        return m_shape.getGlobalBounds() == other.m_shape.getGlobalBounds();
    }


private:
    sf::RectangleShape m_shape;
    sf::Texture m_bullets;
    float m_speed;
};
