#include "../inc/Map.hpp"

/*
*	brief:	Load all the map
*	params:	std::string &, sf::Vector2u, int *, unsigned int, unsigned int
*	return:	void
*/
bool    load(std::string const &tileset, sf::Vector2u tileSize, int const *tiles,
				unsigned int width, unsigned int height)
{
	// load texture from tileset file
	if (!this->_tileSet.loadFromFile(tileset))
		throw std::logic_error("");
	// set size of vertex array
	this->_vertices.setPrimitiveType(sf::Quads);
	this->_vertices.resize(width * height * 4);
	//fill vertex array with quad per tile
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			// current tile
			int	tile_nb = tiles[i + j * width];
			// sett his position
			int	tu = tile_nb % (this->_tileSet.getSize().x / tileSize.x);
			int	tv = tile_nb / (this->_tileSet.getSize().x / tileSize.x);
			//rec ptr of quad to define in vertex array
			sf::Vertex	*quad = &this->_vertices[(i + j * width) * 4];
			//define four corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i = 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			//define coord of texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return (true);
}

/*
*	brief:	Draw all the map in window
*	params:	sf::renderTarget &, sf::RenderStates &
*	return:	void
*/
void	Map::draw(sf::renderTarget &target, sf::RenderStates &states) const
{
	//set the transformation
	states.transform *= getTransform();
	// set the tileset texture
	states.texture = &this->_tileSet;
	// draw array of vertex
	target.draw(this->_vertices, states);
}
