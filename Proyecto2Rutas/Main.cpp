#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cargar mapa");

    // Cargar una textura desde un archivo de imagen
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Axton Urbina\\source\\repos\\Proyecto2Rutas\\MapaProyecto.png"))
    {
        // Si no se puede cargar la imagen, imprimir error
        return -1;
    }

    // Crear un sprite que utilizará la textura
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el sprite (imagen)
        window.draw(sprite);

        // Mostrar los cambios en pantalla
        window.display();
    }

    return 0;
}