#include "RuteNode.h"

RuteNode::RuteNode(string _name)
{
	this->name = _name;
}

void RuteNode::setName(string _name)
{
	this->name = _name;
}

string RuteNode::getName()
{
	return name;
}

void RuteNode::setPointList(PointList _pointList)
{
	this->pointList = _pointList;
}

PointList& RuteNode::getPointList()
{
	return this->pointList;
}

void RuteNode::setNext(RuteNode* _next)
{
	this->next = _next;
}

RuteNode* RuteNode::getNext()
{
	return this->next;
}

void RuteNode::setPrev(RuteNode* _prev)
{
	this->prev = _prev;
}

RuteNode* RuteNode::getPrev()
{
	return this->prev;
}
