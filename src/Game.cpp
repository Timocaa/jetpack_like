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
				_player(),
				_input(),
				_map(),
				_item(),
				_info()
{
	// window creation and settings
	this->_window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Game", sf::Style::Default);
	// vsync activation
	this->_window.setVerticalSyncEnabled(true);
//	this->_window.setFramerateLimit(26);
	
	
	
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
		this->_input.handlerEvent(this->_player, this->_mapCollisionLoaded);
		// manage items
		this->_item.handlerItems(this->_player, this->_mapCollisionLoaded);
		// update infos
		this->_info.update(this->_player);
		
		// draw background of the window
		this->_window.clear(sf::Color::Black);
		// draw the map
		this->_window.draw(this->_map);
		// draw player
		this->_window.draw(this->_player.getSprite());
		// draw all items
		this->_item.draw(this->_window);
		// draw all info for game
		this->_info.draw(this->_window);
		// display image drawing in the window
		this->_window.display();
	}
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
