#pragma once
#include "RouteNode.h"

class RouteList {

private:
	RouteNode* head;
	PointList pointList;

public:
	RouteList();

	void insertRoute(string name);
	RouteNode* searchRoute(string name);
	bool isUniqueName(string name);
	void insertPointToRoute(const string& routeName, const string& pointName, int x, int y);
	bool removeRoute(string name);
	void showRoutes();

	RouteNode* getHead();


};