#include "../inc/Items.hpp"

/*
*	brief:	Default constructor
*	params:	void
*	return:	void
*/
Items::Items(): _gaz()
{
}

/*
*	brief:	Copy constructor
*	params:	Items const &
*	return:	void
*/
Items::Items(Items const &rhs)
{
	*this = rhs;
}

/*
*	brief:	Assignement operator
*	params:	Items const &
*	return:	Items &
*/
Items	&Items::operator=(Items const &rhs)
{
	(void)rhs;
	return (*this);
}

/*
*	brief:	Getter for sprite of gaz 
*	params:	void
*	return:	sf::Sprite &
*/
sf::Sprite	&Items::getGazSprite()
{
	return (this->_gaz.getGazSprite());
}

/*
*	brief:	Getter for need of gaz 
*	params:	void
*	return:	bool
*/
bool	Items::needGaz() const
{
	return (this->_gaz.needGaz());
}

/*
*	brief:	Manage all items in game
*	params:	void
*	return:	void
*/
void	Items::handlerItems(Player &player, int *collisionMap)
{
	// rand for display another gaz item
	if (player.gazQuantity() < MAX_GAZ)
		this->_gaz.randPosition();
	// manage gaz item if in windows or needed
	if (this->_gaz.needGaz())
		this->_gaz.handling(player, collisionMap);
}

/*
*	brief:	Draw all item of game
*	params:	sf::Window &
*	return:	void
*/
void	Items::draw(sf::RenderWindow &window)
{
	if (this->_gaz.needGaz())
			window.draw(this->_gaz.getGazSprite());
}

/*
*	brief:	Destructor
*	params:	void
*	return:	void
*/
Items::~Items()
{
}
