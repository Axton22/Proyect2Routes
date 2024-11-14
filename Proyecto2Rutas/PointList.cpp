#include "PointList.h"

PointList::PointList()
{
	this->head = nullptr;
}

void PointList::insertPoint(const string& pointName, int x, int y)
{
    PointNode* newNode = new PointNode(pointName, x, y);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        PointNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setPrev(current);
    }
}

bool PointList::isUniqueName(string name)
{
    PointNode* current = head;
    while (current != nullptr) {
        if (current->getName() == name) {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

void PointList::showThePoints()
{
    PointNode* current = head;
    while (current != nullptr) {
        cout << current->getName() << ", ";
        current = current->getNext();
    }
}

PointNode* PointList::getHead()
{
    return head;
}


