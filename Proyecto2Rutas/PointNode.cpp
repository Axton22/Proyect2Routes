#include "PointNode.h";


PointNode::PointNode(string _name, int _x, int _y)
{
	this->name = _name;
	this->x = _x;
	this->y = _y;
	this->next = nullptr;
	this->prev = nullptr;
}

void PointNode::setName(string _name)
{
	this->name = _name;
}

string PointNode::getName()
{
	return name;
}

void PointNode::setX(int _x)
{
	this->x = _x;
}

int PointNode::getX()
{
	return x;
}

void PointNode::setY(int _y)
{
	this->y = _y;
}

int PointNode::getY()
{
	return y;
}

void PointNode::setNext(PointNode* _next)
{
	this->next = _next;
}

PointNode* PointNode::getNext()
{
	return this->next;
}

void PointNode::setPrev(PointNode* _prev)
{
	this->prev = _prev;
}

PointNode* PointNode::getPrev()
{
	return this->prev;
}


