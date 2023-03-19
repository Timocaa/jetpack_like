/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Game.cpp                              ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:47:55           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 19:51:55           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Game.hpp"

/*
*	brief:	default constructor
*	params:	void
*	return:	void
*/
Game::Game():	_window(),
				_font(),
				_player(),
				_input(),
				_map()
{
	// window creation and settings
	this->_window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Game", sf::Style::Default);
	// vsync activation
	this->_window.setVerticalSyncEnabled(true);
//	this->_window.setFramerateLimit(26);
	
	// load font for text
	if(!this->_font.loadFromFile("res/font/Anglican.ttf"))
		throw std::logic_error("");
	// load and rec first map from file
	this->mapLoader("res/map/map_1.map", 0);
	if (!this->_map.load("res/sprites/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), _mapLoaded, COLS, LINES))
		throw std::logic_error("");
	// load and rec first map collision from file
	this->mapLoader("res/map/map_1_col.map", 1);
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
		// manage keyboard events
		this->_input.handlerInput(event, this->_window, this->_player);
		this->_input.checkBtn(this->_player, this->_mapCollisionLoaded);

		// for display in the window
		this->_window.clear(sf::Color::Black);
	
		this->_window.draw(this->_map);
		this->_window.draw(this->_player.getSprite());

		//for debug collisions
		for (unsigned int j = 0; j < 18; j++)
		{
			for (unsigned int i = 0; i < 25; i++)
			{
				if (this->_mapCollisionLoaded[i + j * 25])
				{
					sf::Vector2f	pos = sf::Vector2f(i * SPRITE_SIZE, j * SPRITE_SIZE);
					this->_rects[i + j * 25].setPosition(pos);
					this->_rects[i + j * 25].setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
					this->_rects[i + j * 25].setFillColor(sf::Color(250, 0, 0, 100));
				//	this->_window.draw(this->_rects[i + j * 25]);
				}
			}
		}

		//end of debug mode

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
*	brief:	open and check file map
*	params:	std:::string &
*	return:	void
*/
void	Game::mapLoader(std::string const &file_map, int type)
{
	// load map from file
	std::ifstream	flux(file_map);
	if (!flux.is_open())
		throw std::logic_error("Failed to load image \"res/map/map_*\". Reason: Unable to open file\n");
	// rec data's map in a string
	std::string	content((std::istreambuf_iterator<char>(flux)), (std::istreambuf_iterator<char>()));
	size_t	i = 0;
	std::vector<int>	exploded;
	for (; i < content.size() - 1; i++)
	{
		int	box = 0;
		if (i % 2 == 0 && !std::isdigit(content[i]))
		{
			std::cout<< content[i] <<std::endl;throw std::logic_error("Error: map not compliant: a non-digit data detected...\n");
		}
		else if (i % 2 == 1 && content[i] != ' ')
			throw std::logic_error("Error: map not compliant: separator not a space...\n");
		else
		{
			if (!(i % 2))
			{
				if (box > 450)
					throw std::logic_error("Error: map not compliant: map too long...\n");
				char nb = content[i];
				exploded.push_back(std::atoi(&nb));
				if (type == 0)
				{
					if (exploded[box] < 0 || exploded[box] > 3)
						throw std::logic_error("Error: Map: value not compilant...\n");
				}
				else if (type == 1)
				{
					if (exploded[box] < 0 || exploded[box] > 1)
						throw std::logic_error("Error: Map_collision: value not compilant...\n");
				}
				box++;
				
			}
		}
	}
	if (type == 0)
		for (int i = 0; i < 450; i++)
			this->_mapLoaded[i] = exploded[i];
	else if (type == 1)
		for (int i = 0; i < 450; i++)
			this->_mapCollisionLoaded[i] = exploded[i];
}

/*
*	brief:	destructor
*	params:	void
*	return:	void
*/
Game::~Game()
{

}
