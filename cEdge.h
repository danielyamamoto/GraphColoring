#include "cNode.h"

class Edge {
  public: 
    int weight;
    Node* first;
    Node* second;

    Edge(Node* _first, Node* _second, int _weight);
};