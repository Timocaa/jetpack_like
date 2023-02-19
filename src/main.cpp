#include "../inc/main.hpp"

//global variable
sf::Font            font;
sf::Text            txt;
sf::RenderWindow    window;
sf::CircleShape     circle;
Input               input;
int                 posX = 20;
int                 posY = 200;
sf::Vector2i        mousePos;

int main()
{
    // window option
    sf::ContextSettings option;
    option.antialiasingLevel = 8;
    // window creation 
    sf::VideoMode   desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(WIN_WIDHT, WIN_HEIGHT, desktop.bitsPerPixel), "... New Game ...", sf::Style::Default, option);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    // vsync activation
    window.setVerticalSyncEnabled(true);
    // loading font
    if (!loadFont())
        return (0);
    // text initialisation
    initText("Hello World...!");

    //create circle
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
            chckBtn();
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

// check if font is propely established
bool    loadFont()
{
    if (!font.loadFromFile("res/Anglican.ttf")) //set the path of font depending launch
    {
        std::cerr << "Error loading font..." << std::endl;
        return (false);
    }
    return (true);
}

//set text option
void    initText(std::string  const str)
{
    // set the font for text
    txt.setFont(font);
    // set characters in text
    txt.setString(str);
    // set height of font
    txt.setCharacterSize(42);
    // set color of text
    txt.setFillColor(sf::Color::Cyan);
    // set style of text
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void chckBtn()
{
    if (input.getbutton().left == true)
    {
        posX -= STEP;
        if (posX < 5)
            posX = 5;
        initText(std::to_string(posX));
    }
    if (input.getbutton().right == true)
    {
        posX += STEP;
        if (posX > WIN_WIDHT - 105)
            posX = WIN_WIDHT - 105;
        initText(std::to_string(posX));
    }
    if (input.getbutton().up == true)
    {
        posY -= STEP;
        if (posY <= 5)
            posY = 5;
        initText(std::to_string(posY));
    }
    if (input.getbutton().down == true)
    {
        posY += STEP;
        if (posY > WIN_HEIGHT - 105)
            posY = WIN_HEIGHT - 105;
        initText(std::to_string(posY));
    }
    if (input.getbutton().attack == true)
    {
        // record mouse coord and set pos of circle
        mousePos = sf::Mouse::getPosition(window);
        std::cout << "mouse.x = " << mousePos.x << "\n" << "mouse Y = " << mousePos.y << "\n\n";
        posX = mousePos.x - 50;
        posY = mousePos.y - 50;
        initText("Attack");
    }
}