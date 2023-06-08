#include <bits/stdc++.h>
using namespace std;
 
#define V 6
 
void prim_MST(int graph[V][V]) {
    int parent[V];
    int weight[V];
    bool mst[V];

    // Initialize weights to all vertices from the current tree to infinite
    for (int i = 0; i < V; i++) {
        weight[i] = INT_MAX; 
        mst[i] = false;
    }

    // Set vertex 0 as the starting vertex
    weight[0] = 0;
    parent[0] = -1;

    // Building the MST
    for (int i = 0; i < V-1; i++) {
        // Finding the vertex with the minimum weight from the current tree
        int min = INT_MAX; 
        int min_vertex;

        for (int v = 0; v < V; v++) {
            if (mst[v] == false && weight[v] < min) {
                min = weight[v]; 
                min_vertex = v;
            }
        }

        // Finding the weights to the adjacent vertices of the current tree 
        int u = min_vertex;
        mst[u] = true;

        for (int v = 0; v < V; v++) {
            if ((graph[u][v]) && (mst[v] == false) && (graph[u][v] < weight[v])) {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
 

    // Print MST
    cout << "Edge  " << "   Weight" << "\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "  :   " << graph[i][parent[i]] << "\n"; 
    }   
}
 

int main() {
    int graph[V][V] = { { 0,  3,  0,  0,  0,  1},
                        { 3,  0,  2,  1, 10,  0},
                        { 0,  2,  0,  3,  0,  5},
                        { 0,  1,  3,  0,  5,  0},
                        { 0, 10,  0,  5,  0,  4},
                        { 1,  0,  5,  0,  4,  0} };

    prim_MST(graph);
    return 0;
}