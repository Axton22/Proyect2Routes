#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
    if (!loadFont("C:\\Users\\Axton Urbina\\source\\repos\\Proyecto2Rutas\\Resources\\arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(-1);
    }
}

sf::Vector2f InterfaceManager::cubicBezier(const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t)
{
    float u = 1 - t;
    return u * u * u * p0 +
        3 * u * u * t * p1 +
        3 * u * t * t * p2 +
        t * t * t * p3;
}

bool InterfaceManager::loadFont(const std::string& fontPath)
{
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Error loading font!" << std::endl;
        return false;
    }
    return true;
}

void InterfaceManager::drawPointsWithNames(sf::RenderWindow& window, RouteNode* route)
{
    sf::Color currentColor = route->getColor();
    PointNode* point = route->getPointList().getHead();
    while (point != nullptr) {
        sf::CircleShape circle(7);
        circle.setPosition(point->getX() - 7, point->getY() - 7);
        circle.setFillColor(currentColor);
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        text.setString(point->getName());
        text.setCharacterSize(15);
        text.setFillColor(route->getColor());
        text.setPosition(point->getX() + 10, point->getY() - 10);

        window.draw(text);

        point = point->getNext();
    }
}

void InterfaceManager::drawCubicBezierCurve(sf::RenderWindow & window, RouteNode * route, int numInterpolatedPoints, float thickness)
{
    PointNode* current = route->getPointList().getHead();
    sf::Color currentColor = route->getColor();

    while (current && current->getNext() != nullptr) {
        sf::Vector2f p0(current->getX(), current->getY());
        sf::Vector2f p3(current->getNext()->getX(), current->getNext()->getY());

        sf::Vector2f p1, p2;

        if (current->getPrev()) {
            sf::Vector2f prev(current->getPrev()->getX(), current->getPrev()->getY());
            p1 = p0 + (p0 - prev) * 0.3f;
        }
        else {
            p1 = p0;
        }

        if (current->getNext()->getNext()) {
            sf::Vector2f next(current->getNext()->getNext()->getX(), current->getNext()->getNext()->getY());
            p2 = p3 - (next - p3) * 0.3f;
        }
        else {
            p2 = p3;
        }

        for (int i = 1; i <= numInterpolatedPoints; ++i) {
            float t1 = (i - 1) / static_cast<float>(numInterpolatedPoints);
            float t2 = i / static_cast<float>(numInterpolatedPoints);
            sf::Vector2f point1 = cubicBezier(p0, p1, p2, p3, t1);
            sf::Vector2f point2 = cubicBezier(p0, p1, p2, p3, t2);

            sf::Vector2f direction = point2 - point1;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= length;

            sf::RectangleShape thickLine(sf::Vector2f(length, thickness));
            thickLine.setPosition(point1);
            thickLine.setFillColor(currentColor);

            float angle = std::atan2(direction.y, direction.x) * 180 / 3.14159f;
            thickLine.setRotation(angle);

            window.draw(thickLine);
        }

        current = current->getNext();
    }
}
