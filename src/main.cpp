#include "../inc/main.hpp"

//global variable
Input               input;
int                 posX = 20;
int                 posY = 200;
sf::Vector2i        mousePos;

int main()
{
    sf::RenderWindow    window;
    sf::Text            txt;
    sf::Font            font;


    // window init
    init_game(window, font);
    // text initialisation
    initText(txt, font, "Hello World...!");

    //create circle
    sf::CircleShape     circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color(109, 158, 235));
    circle.setOutlineColor(sf::Color::Green);
    circle.setOutlineThickness(5);
    // create triangle
    sf::CircleShape triangle(42, 3);
    triangle.setFillColor(sf::Color::Blue);
    // create free form
    sf::ConvexShape form;
    form.setPointCount(5);
    form.setPoint(0, sf::Vector2f(0.f, 0.f));
    form.setPoint(1, sf::Vector2f(150.f, 10.f));
    form.setPoint(2, sf::Vector2f(120.f, 90.f));
    form.setPoint(3, sf::Vector2f(30.f, 100.f));
    form.setPoint(4, sf::Vector2f(0.f, 50.f));
    form.setFillColor(sf::Color(10, 200, 120));

    // stop if window is closed
    while (window.isOpen())
    {
        sf::Event   event;
        while (window.pollEvent(event))
        {
            // management inputs and event
            input.inputHandler(event, window);
            chckBtn(window);
            circle.setPosition(posX, posY);

        }

        // set background window in black 
        window.clear(sf::Color::Black);

        // here all modifications for the window
        window.draw(txt);
        window.draw(circle);
        window.draw(triangle);

        // display all modifications in the window
        window.display();
    }
    
    // end of programm
    return 0;
}

void chckBtn(sf::RenderWindow &window)
{
    if (input.getbutton().left == true)
    {
        posX -= STEP;
        if (posX < 5)
            posX = 5;
    }
    if (input.getbutton().right == true)
    {
        posX += STEP;
        if (posX > WIN_WIDHT - 105)
            posX = WIN_WIDHT - 105;
    }
    if (input.getbutton().up == true)
    {
        posY -= STEP;
        if (posY <= 5)
            posY = 5;
    }
    if (input.getbutton().down == true)
    {
        posY += STEP;
        if (posY > WIN_HEIGHT - 105)
            posY = WIN_HEIGHT - 105;
    }
    if (input.getbutton().attack == true)
    {
        // record mouse coord and set pos of circle
        mousePos = sf::Mouse::getPosition(window);
        std::cout << "mouse.x = " << mousePos.x << "\n" << "mouse Y = " << mousePos.y << "\n\n";
        posX = mousePos.x - 50;
        posY = mousePos.y - 50;
        std::cout << "attack Button" << std::endl;
    }
}