//#include "../inc/main.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// check if font is propely established
bool    loadFont()
{
    if (!font.loadFromFile("../res/Angican.ttf"))
    {
        std::cerr << "Error loading font..." << std::endl;
        return (false);
    }
    return (true);
}