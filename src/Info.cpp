#include "../inc/Info.hpp"

/*
*   brief:  Default constructor
*   params: void
*   return: void
*/
Info::Info(): _font()
{
    // load font for text
	if(!this->_font.loadFromFile("res/font/space_age.ttf"))
		throw std::logic_error("");
    this->initText(this->_gaz, "Jetpack:");
    this->initText(this->_gazValue, "100%");
    this->_gazValue.setPosition(120, 0);
}

/*
*   brief:  Copy constructor
*   params: Info const &
*   return: void
*/
Info::Info(Info const &rhs)
{
    *this = rhs;
}

/*
*   brief:  Assignement operator
*   params: Info const &
*   return: Info &
*/
Info    &Info::operator=(Info const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
*	brief:	Init txt for display
*	params:	sf::Text &, std::string const&
*	return:	void
*/
void    Info::initText(sf::Text &txt, std::string const &str)
{
    // set the font for text
    txt.setFont(this->_font);
    // set characters in text
 	if (str.size())
		txt.setString(str);
    // set height of font
    txt.setCharacterSize(18);
    // set color of text
    txt.setFillColor(sf::Color::Green);
    // set style of text
    //txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

/*
*   brief:  Update all information valuesfor draw
*   param:  Player &
*   return: void
*/
void    Info::update(Player &player)
{
    std::string q_gaz = std::to_string((player.gazQuantity() * 100) / MAX_GAZ);
    q_gaz += "%";
    this->initText(this->_gazValue, q_gaz);
}

/*
*   brief:  Display all information in game
*   param:  sf::renderWindow &
*   return: void
*/
void    Info::draw(sf::RenderWindow &window)
{
    window.draw(this->_gaz);
    window.draw(this->_gazValue);
}

/*
*   brief:  Destructor
*   params: void
*   return: void
*/
Info::~Info()
{
}