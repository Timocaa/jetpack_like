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
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
