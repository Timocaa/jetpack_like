#include "../inc/main.hpp"

int	main()
{
	try
	{
		Game game;
		game.start();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return (1);
	}

	return (0);
}
