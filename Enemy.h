#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float x, float y, const sf::Texture& texture);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();

    bool operator==(const Enemy& other) const {
        return m_shape.getGlobalBounds() == other.m_shape.getGlobalBounds();
    } 

private:
    sf::RectangleShape m_shape;
    const sf::Texture* m_texture;
    float m_speed;
};
#endif