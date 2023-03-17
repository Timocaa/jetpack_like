#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public: sf::Transformable
{
	public:
		//---- member method ----//
		bool	load(std::string const &tileset, sf::Vector2u tilesize, int const *tiles,
					unsigned int width, unsigned int height);

	private:
		//---- member object ----//
			//define entity with coord and texture
		sf::VertexArray	_vertices;
			//texture of map
		sf::Texture		_tileSet;

		//---- private methods ----//
		virtual void	draw(sf::renderTarget &target, sf::RenderStates &states) const;

};

#endif
