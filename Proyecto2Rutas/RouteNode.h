#pragma once
#include <string>
#include "PointList.h"

using namespace std;

class RouteNode {
private:
	string name;
	PointList pointList;
	RouteNode* next;
	RouteNode* prev;

public:
	RouteNode() {}
	RouteNode(string _name);

	void setName(string _name);
	string getName();

	void setPointList(PointList _pointList);
	PointList& getPointList();

	void setNext(RouteNode* _next);
	RouteNode* getNext();

	void setPrev(RouteNode* _prev);
	RouteNode* getPrev();


};