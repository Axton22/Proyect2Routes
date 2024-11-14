#pragma once

#include <string>

using namespace std;
class PointNode {

private:
	string name;
	int x;
	int y;
	PointNode* next;
	PointNode* prev;

public:
	PointNode() {}
	PointNode(string _name, int _x, int _y);

	void setName(string _name);
	string getName();

	void setX(int _x);
	int getX();

	void setY(int _y);
	int getY();

	void setNext(PointNode* _next);
	PointNode* getNext();
	void setPrev(PointNode* _prev);
	PointNode* getPrev();

};