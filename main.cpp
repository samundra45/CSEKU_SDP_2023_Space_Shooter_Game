#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Score.h"
#include <vector>
#include <cstdlib>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Shooter");

    sf::Font font;
    if (!font.loadFromFile("fonts/AGENCYB.TTF")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }
    sf::Text playText("Start Game", font, 50);
    playText.setFillColor(sf::Color::Red);
    playText.setPosition(window.getSize().x / 2.0f - playText.getLocalBounds().width / 2.0f, window.getSize().y / 2.0f - playText.getLocalBounds().height / 2.0f);


    // Create player object
    Player player(window.getSize().x / 2.0f, window.getSize().y - 100.0f);

    // Create enemies
    std::vector<Enemy> enemies;

    
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("images/enemy.png")) {
        std::cerr << "Failed to load enemy texture!" << std::endl;
        return 1;
    }

    // Create bullets
    std::vector<Bullet> bullets;

    // Create score object
    Score score(window);
    int totalScore = 0;

    // Game loop
    bool gameStarted = false;
    sf::Clock clock;
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (playText.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    gameStarted = true;
                }
            }
            else if (event.type == sf::Event::KeyPressed && gameStarted)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    bullets.emplace_back(player.getGlobalBounds().left + player.getGlobalBounds().width / 2.0f, player.getGlobalBounds().top);
                }
            }
        }

        // Draw play button if game not started
        if (!gameStarted)
        {
            window.clear(sf::Color::Black);
            window.draw(playText);
            window.display();
            continue;
        }

        // Generate enemies randomly
        if (rand() % 1200 == 0) {
            Enemy enemy(rand() % (window.getSize().x - 50), 50.0f, enemyTexture);
            enemies.emplace_back(enemy);
        }

        // Update player
        player.update(deltaTime);

        // Update enemies
        for (auto& enemy : enemies) {
            enemy.update(deltaTime);
        }

        // Update bullets
        for (auto& bullet : bullets) {
            bullet.update(deltaTime);
        }

      
        for (auto& enemy : enemies) {
            for (auto& bullet : bullets) {
                if (enemy.getGlobalBounds().intersects(bullet.getGlobalBounds())) {
                    totalScore++;
                    score.increment();
                    enemies.erase(std::find(enemies.begin(), enemies.end(), enemy));
                    bullets.erase(std::find(bullets.begin(), bullets.end(), bullet));
                    break;
                }
            }
            if (enemy.getGlobalBounds().intersects(player.getGlobalBounds())) {

                sf::Font font;
                if (!font.loadFromFile("fonts/AGENCYB.TTF")) {
                    std::cerr << "Failed to load font!" << std::endl;
                    return 1;
                }
                sf::Text text("Game over! Total Score: " + std::to_string(totalScore), font, 50);
                text.setFillColor(sf::Color::Red);
                text.setPosition(window.getSize().x / 2.0f - text.getLocalBounds().width / 2.0f, window.getSize().y / 2.0f - text.getLocalBounds().height / 2.0f);
                window.clear(sf::Color::Black);
                window.draw(text);
                window.display();
                sf::sleep(sf::seconds(10));
                window.close();
            }
        }

        // Draw objects
        window.clear(sf::Color::Black);
        player.draw(window);
        for (auto& enemy : enemies) {
            enemy.draw(window);
        }
        for (auto& bullet : bullets) {
            bullet.draw(window);
        }
        score.draw();
        window.display();
    }

    return 0;
}
