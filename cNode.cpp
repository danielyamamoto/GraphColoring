#include "cNode.h"

// Complejidad O(1)
Node::Node(int _number) {
  number = _number;
  prev = nullptr;
  distance = 1000;
  color = -1;
}

// Complejidad O(1)
void Node::setColor(int newColor) { color = newColor; }

// Complejidad O(1)
int Node::getColor() { return color; }

// Complejidad O(1)
int Node::getNumber() { return number; }