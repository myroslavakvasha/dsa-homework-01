#include <SFML/Graphics.hpp>
#include <iostream>

#include "Flower.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

    Flower flower(&window);

    //ability to change the flower
    /*flower.setHeadColor(sf::Color::White);
    flower.setHeadRadius(30.f);
    flower.setNumOfPetals(12);
    flower.setPetalWidth(5);*/

    flower.draw();

}