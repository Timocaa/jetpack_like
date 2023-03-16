#include "../inc/Game.hpp"

/*
*	brief:	default constructor
*	params:	void
*	return:	void
*/
Game::Game():	_window(),
				_font(),
				_input()
{
	this->_window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Game", sf::Style::Default);
	// vsync activation
	this->_window.setVerticalSyncEnabled(true);
	// load font for text
	if(!this->_font.loadFromFile("res/font/Anglican.ttf"))
		throw std::logic_error("Error: loading font failed...");
}

/*
*	brief:	copy constructor
*	params:	Game const&
*	return:	void
*/
Game::Game(Game const &rhs)
{
	*this = rhs;
}

/*
*	brief:	assignement operator
*	params:	Game const&
*	return:	Game &
*/
Game	&Game::operator=(Game const &rhs)
{
	(void)rhs;
	return (*this);
}

/*
*	brief:	Loop main game
*	params:	void
*	return:	void
*/
void	Game::start()
{
	while (this->_window.isOpen())
	{
		sf::Event	event;
		this->_input.handlerInput(event, this->_window);
		this->_input.checkBtn(this->_txt);
		

		this->_window.clear(sf::Color::Black);


		this->_window.display();
	}
}

/*
*	brief:	Init txt for display
*	params:	std::string const&
*	return:	void
*/
void    Game::initText(std::string const &str)
{
    // set the font for text
    this->_txt.setFont(this->_font);
    // set characters in text
 	if (str.size())
		this->_txt.setString(str);
    // set height of font
    this->_txt.setCharacterSize(42);
    // set color of text
    this->_txt.setFillColor(sf::Color::Cyan);
    // set style of text
    this->_txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

/*
*	brief:	destructor
*	params:	void
*	return:	void
*/
Game::~Game()
{

}
