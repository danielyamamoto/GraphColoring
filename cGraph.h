#include "cEdge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Graph {
  public: 
    vector<Node*> nodes;
    vector<Edge*> edges;
    int vertex;
    
    // Constructores
    Graph(vector<Node*> _nodes, vector<Edge*> _edges);
    Graph(vector<vector<int>> v);

    // Métodos
    vector<Node*> getNeighbors(Node* n);
    void coloring();
};