#pragma once
#include <SFML/Graphics.hpp>

class Flower {
public:
	Flower(sf::RenderWindow* window);
	void setPetalsColor(sf::Color color);
	void setStemColor(sf::Color color);
	void setHeadColor(sf::Color color);
	void setLeafColor(sf::Color color);
	void setNumOfPetals(int numOfPetals);
	void setPetalWidth(int petalWidth);
	void setHeadRadius(float headRadius);
	void draw();
private:
	sf::RenderWindow* window;
	sf::ConvexShape petals, leaf;
	sf::CircleShape head;
	sf::RectangleShape stem;
	int numOfPetals, petalWidth;
	float headRadius;
	sf::Clock clock;
};