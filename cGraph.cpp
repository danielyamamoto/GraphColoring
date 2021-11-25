#include "cGraph.h"

// Complejidad O(1)
Graph::Graph(vector<Node*> _nodes, vector<Edge*> _edges) {
    nodes = _nodes;
    edges = _edges;
}

// Liga del push_back: https://www.hackerearth.com/practice/notes/standard-template-library/
// Complejidad O(n^2)
Graph::Graph(vector<vector<int>> v) {
    // Genera los nodos
    for (int i = 0; i < v.size(); i++) {
        nodes.push_back(new Node(i)); // Complejidad O(1)
    }
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            // Crea las aristas según se tenga en la matriz, si el valor es mayor a 0
            if (v[i][j] > 0) {
                edges.push_back(new Edge(nodes[i], nodes[j], v[i][j])); // Complejidad O(1)
            }
        }
    }  
}

// DFS
// Complejidad O(n)
vector<Node*> Graph::getNeighbors(Node* n) {
    vector<Node*> neighbors;
    for (vector<Edge*>::iterator ei = edges.begin(); ei != edges.end(); ei++) {
        if ((*ei)->first == n) {
            neighbors.push_back((*ei)->second); // Complejidad O(1)
        } else if ((*ei)->second == n) {
            neighbors.push_back((*ei)->first); // Complejidad O(1)
        }
    }
    return neighbors;
}

// Complejidad O(n^2)
void Graph::coloring() {
    // Valor máximo para asignar color
    int maxColorAssign = 10; 
    // Se recorren todos los nodos
    for (vector<Node*>::iterator ni = nodes.begin(); ni < nodes.end(); ++ni) {
        int futureColor = 0;
        vector<Node*> neighbors = getNeighbors(*ni); // Complejidad O(n)
        
        for (vector<Node*>::iterator ne = neighbors.begin(); ne < neighbors.end(); ++ne) {
            // Si el color a asignar se repite en algún vecino del nodo, se cambia el color
            if ((*ne)->getColor() == futureColor) {
                futureColor++;
            } else if (futureColor >= maxColorAssign) { 
                futureColor = -1;
                break;
            }
        }

        (*ni)->setColor(futureColor);
        // Si se tiene un color válido, se imprime
        if (futureColor != -1) {
            cout << "Node: " << (*ni)->getNumber() << ", Assigned Color: " << (*ni)->getColor() << "\n";
        } else {
            cout << "Node: " << (*ni)->getNumber() << ", No es posible asignar colores al nodo\n";
        }
    }
}