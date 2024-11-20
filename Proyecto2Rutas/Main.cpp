#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "RouteList.h"
#include "InterfaceManager.h"

int main()
{
    bool isRouteAvailable = false;
    bool insertMode = false;
    sf::Font font;
    InterfaceManager interfaceManager;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cargar mapa");
    RouteList routeList;
    PointList pointList;
    string routeName;

    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Axton Urbina\\source\\repos\\Proyecto2Rutas\\MapaProyecto.png"))
    {
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    cout << "Bienvenidos al sistema de rutas" << endl << endl;
    cout << "Presione 'C' si desea crear una ruta " << endl;
    cout << "Presione 'X' si desea salir del sistema " << endl << endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
            {
                insertMode = !insertMode;
                if (insertMode) {
                    cout << "Nombre de la ruta: ";
                    getline(cin, routeName);

                    if (routeList.isUniqueName(routeName)) {
                        routeList.insertRoute(routeName);

                        cout << "Ruta creada: " << routeName << endl;
                        insertMode = true;
                        cout << "\n -> Por favor haz clic en el lugar del mapa que deseas ingresar tu punto " << endl;
                        cout << "-> O presiona 'ENTER' si deseas finalizar la ruta " << endl << endl;
                    }
                    else {
                        cout << "El nombre de la ruta ya existe. Por favor, elige otro nombre." << endl;
                        insertMode = false;
                    }
                }
            }

            if (insertMode && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
                insertMode = false;
                cout << "Ruta finalizada y guardada." << endl;
                isRouteAvailable = true;

                cout << "Presione 'C' si desea crear otra ruta " << endl;
                cout << "Presione 'D' si desea eliminar una ruta " << endl;
                cout << "Presione 'X' si desea salir del sistema " << endl << endl;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
            {
                if (isRouteAvailable)
                {
                    string routeToEliminate;
                    cout << "Digite el nombre de la ruta que desea eliminar: ";
                    getline(cin, routeToEliminate);

                    if (routeList.removeRoute(routeToEliminate))
                    {
                        cout << "Ruta eliminada: " << routeToEliminate << endl;
                    }
                    else
                    {
                        cout << "La ruta no existe o no pudo ser eliminada." << endl;
                    }
                }
                else
                {
                    cout << "No hay rutas disponibles para eliminar." << endl;
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
            {
                window.close();  
                return 0;     
            }

            if (insertMode && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                string pointName;
                cout << "Nombre del punto turistico: ";
                getline(cin, pointName);

                routeList.insertPointToRoute(routeName, pointName, x, y);

                RouteNode* currentRoute = routeList.searchRoute(routeName);
                if (currentRoute) {
                    interfaceManager.drawPointsWithNames(window, currentRoute);
                    window.display();
                }
            }
        }

        window.clear();
        window.draw(sprite);

        RouteNode* currentRoute = routeList.getHead();
        while (currentRoute != nullptr) {
            interfaceManager.drawCubicBezierCurve(window, currentRoute, 10, 5.0f);
            interfaceManager.drawPointsWithNames(window, currentRoute);
            currentRoute = currentRoute->getNext();
        }
        window.display();
    }

    return 0;
}
