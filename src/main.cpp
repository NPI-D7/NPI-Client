#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main(int argc, char*argv[])
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "NPI-Client");
    sf::Texture tex;
    sf::Sprite spr;
    sf::Image img;
    sf::Font fnt;
    fnt.loadFromFile("Font.ttf");
    sf::Text txt(sf::String("Hello!"), fnt);
    img.loadFromFile("icon.png");
    window.setIcon(48, 48, img.getPixelsPtr());
    tex.loadFromFile("bg.jpg");
    
    spr.setTexture(tex);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spr);
        window.draw(txt);
        window.display();
    }

    return 0;
}