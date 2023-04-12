#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();


private:
    sf::RectangleShape m_shape;
    sf::Texture m_sprite;
    float m_speed;
};
