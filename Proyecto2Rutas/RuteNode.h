#pragma once
#include <string>
#include "PointList.h"

using namespace std;

class RuteNode {
private:
	string name;
	PointList pointList;
	RuteNode* next;
	RuteNode* prev;

public:
	RuteNode() {}
	RuteNode(string _name);

	void setName(string _name);
	string getName();

	void setPointList(PointList _pointList);
	PointList& getPointList();

	void setNext(RuteNode* _next);
	RuteNode* getNext();

	void setPrev(RuteNode* _prev);
	RuteNode* getPrev();


};