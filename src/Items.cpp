#include "../inc/Items.hpp"

/*
*	brief:	Default constructor
*	params:	void
*	return:	void
*/
Items::Items(): _gazTexture(), _gazSprite(), _clockAnim(),
				_clockItemPop() ,_anim(), _falling(true),
				_gaz(false),
				_rand(std::chrono::system_clock::now().time_since_epoch().count())
{
	// load texture for gaz item
	if (!this->_gazTexture.loadFromFile("res/sprites/gaz.png"))
		throw std::logic_error("");
	// set texture on gaz sprite
	this->_gazSprite.setTexture(this->_gazTexture);
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
	return (this->_gazSprite);
}

/*
*	brief:	Getter for need of gaz 
*	params:	void
*	return:	bool
*/
bool	Items::needGaz() const
{
	return (this->_gaz);
}

/*
*	brief:	Manage all items in game
*	params:	void
*	return:	void
*/
void	Items::handlerItems(Player &player, int *collisionMap)
{
	// rand for displayey another item
	if (this->_clockItemPop.getElapsedTime().asSeconds() > 5 && !this->_gaz && player.gazQuantity() < 1000)
	{
		int posX = this->_boxRand(this->_rand) * 40;
		this->_gazSprite.setPosition(posX, -40);
		this->_gaz = true;
	}

	// check collision if items is falling
	if (this->_gaz)
	{
		if (this->_falling == true)
		{
			int IPosX = round(this->_gazSprite.getPosition().x / SPRITE_SIZE);
			int IPosY = round((this->_gazSprite.getPosition().y + (SPEED_FALL * 7)) / SPRITE_SIZE);
			if (!collisionMap[IPosX + IPosY * 25])
				this->_gazSprite.move(0, SPEED_FALL);
			else
				this->_falling = false;
		}
		// check collision with player
		sf::FloatRect	playerHitBox = player.getSprite().getGlobalBounds();
		sf::FloatRect	itemHitBox = this->_gazSprite.getGlobalBounds();
		if (playerHitBox.intersects(itemHitBox))
		{
			player.setGaz(250);
			this->_gaz = false;
			this->_falling = true;
			if (player.gazQuantity() < 1000)
				this->_clockItemPop.restart();
		}
		// update animation for items
		this->animItems();
		this->_gazSprite.setTextureRect(sf::IntRect(this->_anim.x * SPRITE_SIZE,
									this->_anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	}
}

/*
*	brief:	Update animation of all items
*	params:	void
*	return:	void
*/
void	Items::animItems()
{
	// check time passed for change the sprite of player
	if (this->_clockAnim.getElapsedTime().asSeconds() > 0.05f)
	{
		if (!this->_falling)
			this->_anim.x++;
		else
			this->_anim.x = 0;
		if (this->_anim.x > 7)
			this->_anim.x = 0;
		this->_clockAnim.restart();
	}	
}

/*
*	brief:	Destructor
*	params:	void
*	return:	void
*/
Items::~Items()
{
}
