#include "Score.h"
#include <iostream>

Score::Score(sf::RenderWindow& window) :
	score_(0),
	window_(window)
{
	// Load font
	if (!font_.loadFromFile("fonts/AGENCYB.TTF")) {
		std::cerr << "Failed to load font!" << std::endl;
	}
	// Configure text
	text_.setFont(font_);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::Red);
	text_.setOutlineColor(sf::Color::White);
	text_.setOutlineThickness(2.0f);
	text_.setPosition(10.0f, 10.0f);
}

int Score::getScore() const {
	return score_;
}

void Score::increment()
{
	score_++;
}

void Score::gameOver()
{
	// Update text
	text_.setString("Game Over! Final Score: " + std::to_string(score_));
	// Center text
	sf::FloatRect textRect = text_.getLocalBounds();
	text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text_.setPosition(window_.getSize().x / 2.0f, window_.getSize().y / 2.0f);
}

void Score::draw()
{
	// Update text
	text_.setString("Score: " + std::to_string(score_));
	// Draw text
	window_.draw(text_);
}
