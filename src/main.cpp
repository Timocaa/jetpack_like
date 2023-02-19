#include "../inc/main.hpp"

int main()
{
    // game initialisation
    s_game  data;
    init_game(data);
    // text initialisation
    initText(data.txt, data.font, "Hello World...!");

    // load texture file for player
    if (!data.player.loadFromFile("res/test.png"))
        std::cout << "Error: loading " << "res/test.png" << std::endl;
    data.player.setSmooth(true);
    // set texture to the sprite to display
    data.player_sprite.setTexture(data.player);
    data.player_sprite.setPosition(data.posX, data.posY);

    // stop if window is closed
    while (data.window.isOpen())
    {
        sf::Event   event;
        while (data.window.pollEvent(event))
        {
            // management inputs and event
            data.input.inputHandler(event, data.window);
            data.input.chckBtn(data.window, &(data.posX), &(data.posY));
            data.player_sprite.setPosition(data.posX, data.posY);
        }
        // set background window in black 
        data.window.clear(sf::Color::Black);
        // here all modifications for the window
        data.window.draw(data.txt);
        data.window.draw(data.player_sprite);

        // display all modifications in the window
        data.window.display();
    }
    // end of programm
    return 0;
}