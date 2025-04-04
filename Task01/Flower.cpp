#include "Flower.h"

Flower::Flower(sf::RenderWindow* window)
{
	// original settings of the flower
	this->window = window;
	this->headRadius = 50.f;
	this->numOfPetals = 9;
	this->petalWidth = 15;
	petals.setFillColor(sf::Color(153, 204, 255));
	leaf.setFillColor(sf::Color(0, 102, 51));
	stem.setFillColor(sf::Color(0, 102, 51));
	head.setFillColor(sf::Color(255, 255, 153));
}

void Flower::setPetalsColor(sf::Color color)
{
	petals.setFillColor(color);
}

void Flower::setStemColor(sf::Color color)
{
	stem.setFillColor(color);
}

void Flower::setHeadColor(sf::Color color)
{
	head.setFillColor(color);
}

void Flower::setLeafColor(sf::Color color)
{
	leaf.setFillColor(color);
}

void Flower::setNumOfPetals(int numOfPetals)
{
	this->numOfPetals = numOfPetals;
}

void Flower::setPetalWidth(int petalWidth)
{
	this->petalWidth = petalWidth;
}

void Flower::setHeadRadius(float headRadius)
{
	this->headRadius = headRadius;
}

void Flower::draw()
{

	// flower stem
	stem.setSize({ 350.f,5.f });
	stem.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f });
	stem.rotate(sf::degrees(90));

	// flower stem leaf
	leaf.setPointCount(12);
	leaf.setPoint(0, { 0.f,0.f });
	leaf.setPoint(1, { 15.f,-20.f });
	leaf.setPoint(2, { 30.f,-35.f });
	leaf.setPoint(3, { 60.f,-50.f });
	leaf.setPoint(4, { 90.f,-60.f });
	leaf.setPoint(5, { 120.f,-57.f });
	leaf.setPoint(6, { 150.f,-53.f });
	leaf.setPoint(7, { 120.f,-10.f });
	leaf.setPoint(8, { 90.f,15.f });
	leaf.setPoint(9, { 60.f,25.f });
	leaf.setPoint(10, { 30.f,20.f });
	leaf.setPoint(11, { 0.f,0.f });
	leaf.setPosition({ (window->getSize().x / 2.f) - 3.f, (window->getSize().y / 2.f) + 200.f });

	// petals
	int points = numOfPetals * petalWidth;
	float angle = 360.f / points;
	petals.setPointCount(points);
	for (int i = 0; i < points; i++) {
		if ((i + 1) % petalWidth < 3) petals.setPoint(i, sf::Vector2f(headRadius, sf::degrees(i * angle - 90.f)));
		else petals.setPoint(i, sf::Vector2f(headRadius * 2.f, sf::degrees(i * angle - 90.f)));
	}
	petals.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f});

	// flower head
	head.setRadius(headRadius);
	head.setOrigin({ headRadius, headRadius });
	head.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f });

	// drawing
	while (window->isOpen())
	{
	    while (const std::optional event = window->pollEvent())
	    {
	        if (event->is<sf::Event::Closed>())
	            window->close();
	    }

		// animation - 3 sec dance & 5 sec hold
		if (clock.getElapsedTime() < sf::seconds(3)) {
			petals.rotate(sf::degrees(10.f));
		}
		else {
			clock.restart();
			for (sf::Time t = sf::seconds(0); t < sf::seconds(5);) {
				t = clock.getElapsedTime();
			}
			clock.restart();
		}
	
	    window->clear();
		window->draw(stem);
		window->draw(leaf);
		window->draw(petals);
		window->draw(head);
	    window->display();
	}
}
