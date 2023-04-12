#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

class Score {
public:
	Score(sf::RenderWindow& window);
	int getScore() const;
	void increment();
	void gameOver();
	void draw();
private:
	int score_;
	sf::RenderWindow& window_;
	sf::Font font_;
	sf::Text text_;
};

#endif