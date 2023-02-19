#include "../inc/prog.hpp"

// check if font is propely established
bool    loadFont(sf::Font &font)
{
    if (!font.loadFromFile("res/font/Anglican.ttf")) //set the path of font depending launch
    {
        std::cerr << "Error loading font..." << std::endl;
        return (false);
    }
    return (true);
}

bool    init_game(sf::RenderWindow &window, sf::Font &font)
{
    // window option
    sf::ContextSettings option;
    option.antialiasingLevel = 8;
    // window creation 
    sf::VideoMode   desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(WIN_WIDHT, WIN_HEIGHT, desktop.bitsPerPixel), "... New Game ...", sf::Style::Default, option);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    // vsync activation
    window.setVerticalSyncEnabled(true);
    // loading font
    if (!loadFont(font))
        return (false);
    return (true);
}

//set text option
void    initText(sf::Text &txt, sf::Font &font, std::string const str)
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