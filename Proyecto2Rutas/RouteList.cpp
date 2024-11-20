#include "RouteList.h"

RouteList::RouteList()
{
	this->head = nullptr;
}

void RouteList::insertRoute(string name)
{
    RouteNode* newNode = new RouteNode(name);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        RouteNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setPrev(current);
    }
}

RouteNode* RouteList::searchRoute(string name)
{
    RouteNode* current = head;
    while (current != nullptr) {
        if (current->getName() == name) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool RouteList::isUniqueName(string name)
{
    RouteNode* current = head;
    while (current != nullptr) {
        if (current->getName() == name) {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

void RouteList::insertPointToRoute(const string& routeName, const string& pointName, int x, int y)
{
    RouteNode* current = head;
    while (current != nullptr && current->getName() != routeName) {
        current = current->getNext();
    }

    if (current != nullptr) {
        if (current->getPointList().isUniqueName(pointName)) {
            current->getPointList().insertPoint(pointName, x, y);
            cout << "Punto insertado: " << pointName << " en (" << x << ", " << y << ")" << endl << endl;
        }
        else
        {
            cout << "El punto: " << pointName << " ya fue ingresado anteriormente " << endl 
                << "\nHaz clic en el mapa si deseas agregar un nuevo punto o pulsa 'ENTER' para finalizar la ruta" << endl;
        }
    }
}

bool RouteList::removeRoute(string name)
{
    if (head == nullptr) return false;

    if (head->getName() == name) {
        RouteNode* aux = head;
        head = head->getNext();
        delete aux;
        return true;
    }

    RouteNode* current = head->getNext();

    while (current != nullptr) {
        if (current->getName() == name) {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
            return true;
        }
        current = current->getNext();
    }
    return false;

}

void RouteList::showRoutes()
{
    RouteNode* current = head;
    while (current != nullptr) {
        cout << current->getName() << ", ";
        current = current->getNext();
    }
}

RouteNode* RouteList::getHead()
{
    return head;
}



