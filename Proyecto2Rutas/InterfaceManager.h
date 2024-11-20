#pragma once
#include <SFML/Graphics.hpp>
#include "PointNode.h"
#include "RouteNode.h"

class InterfaceManager {

private:
	sf::Font font;

public:

    InterfaceManager();

    sf::Vector2f cubicBezier(const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t);

    bool loadFont(const std::string& fontPath);

    void drawPointsWithNames(sf::RenderWindow& window, RouteNode* route);

    void drawCubicBezierCurve(sf::RenderWindow& window, RouteNode* route, int numInterpolatedPoints, float thickness);
};