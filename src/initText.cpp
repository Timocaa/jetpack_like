#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// check if font is propely established
bool    loadFont(sf::Font &font)
{
    if (!font.loadFromFile("res/Anglican.ttf")) //set the path of font depending launch
    {
        std::cerr << "Error loading font..." << std::endl;
        return (false);
    }
    return (true);
}

//set text option
void    initText(sf::Text &txt, sf::Font &font, std::string  const str)
{
    // set the font for text
    txt.setFont(font);
    // set characters in text
    txt.setString(str);
    // set height of font
    txt.setCharacterSize(42);
    // set color of text
    txt.setFillColor(sf::Color::Cyan);
    // set style of text
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}