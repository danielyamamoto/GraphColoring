/*
Se le asigna un color a cada nodo de un grafo, de tal modo que 
ningún nodo adyacente a otro compartan el mismo color.

Autores:
Yusdivia Molina
Daniel Yamamoto
Héctor Noyola

Fecha de modificación: 18/10/2021
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "cGraph.h"

using namespace std;

// Liga del push_back: https://www.hackerearth.com/practice/notes/standard-template-library/
// Liga del clear: https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
// Complejidad O(n^2)
vector<vector<int>> readFile(string file) {
    vector<vector<int>> board;
    vector<int> tmp;
    string row, num;

    fstream f;
    f.open(file);
    getline(f, row);
    
    for (int i = 0; i < stoi(row); i++) {
        for (int j = 0; j < stoi(row); j++) {
            f >> num;
            tmp.push_back(stoi(num)); // Complejidad O(1)
        }
        board.push_back(tmp); // Complejidad O(1)
        tmp.clear(); // Complejidad O(n)
    }
    f.close();
    return board;
}

int main() {
    vector<vector<int>> matrix = readFile("in.txt"); // Complejidad O(n^2)
    Graph* g = new Graph(matrix);
    g->coloring(); // Complejidad O(n^2)
}