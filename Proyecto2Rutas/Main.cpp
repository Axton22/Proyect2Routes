#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cargar mapa");

    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Axton Urbina\\source\\repos\\Proyecto2Rutas\\MapaProyecto.png"))
    {
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }

    return 0;
}