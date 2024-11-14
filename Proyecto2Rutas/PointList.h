#pragma once
#include <iostream>
#include "PointNode.h"

class PointList {
private:

	PointNode* head;

public:
	PointList();

	void insertPoint(const string& pointName, int x, int y);
	bool isUniqueName(string name);
	void showThePoints();
	PointNode* getHead();


};