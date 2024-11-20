#include "RouteNode.h"

RouteNode::RouteNode(string _name)
{
	color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
	this->name = _name;
}

void RouteNode::setName(string _name)
{
	this->name = _name;
}

string RouteNode::getName()
{
	return name;
}

void RouteNode::setPointList(PointList _pointList)
{
	this->pointList = _pointList;
}

PointList& RouteNode::getPointList()
{
	return this->pointList;
}

void RouteNode::setNext(RouteNode* _next)
{
	this->next = _next;
}

RouteNode* RouteNode::getNext()
{
	return this->next;
}

void RouteNode::setPrev(RouteNode* _prev)
{
	this->prev = _prev;
}

RouteNode* RouteNode::getPrev()
{
	return this->prev;
}

const sf::Color& RouteNode::getColor()
{
	return color;
}
