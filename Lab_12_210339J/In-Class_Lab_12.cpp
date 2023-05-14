#include <iostream>
#include <limits.h>
using namespace std;

#define V 6
      
void dijkstra(int graph[V][V], int start) {
    int time[V]; 
    bool visited[V]; 

    // Initialize travelling times to infinity and all cities as unvisited
    for (int i = 0; i < V; i++) {
        time[i] = INT_MAX; 
        visited[i] = false;
    }
  
    time[start] = 0;
  
    for (int i = 0; i < V - 1; i++) {
        int min_time = INT_MAX; 
        int min_city;
  
        // Find the unvisited city with minimum known travelling time from the starting city
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && time[v] <= min_time) {
                min_time = time[v]; 
                min_city = v;
            }
        }

        int u = min_city;
        visited[u] = true;

        // Find travelling times to the adjacent cities
        for (int v = 0; v < V; v++) {
            if (!visited[v] && (graph[u][v] != 0) && (time[u] != INT_MAX) && (time[u] + graph[u][v] < time[v])) {
                time[v] = time[u] + graph[u][v];
            }
        }
    }

    // Print the final output
    for (int i = 0; i < V; i++) {
        cout << "Time taken from city " << start << " to city " << i << " = " << time[i] << endl;    
    }  
}
  

int main() {
    int graph[V][V] = { { 0, 10,  0,  0, 15,  5},
                        {10,  0, 10, 30,  0,  0},
                        { 0, 10,  0, 12,  5,  0},
                        { 0, 30, 12,  0,  0, 20},
                        {15,  0,  5,  0,  0,  0},
                        { 5,  0,  0, 20,  0,  0} };

    int start = 5;
  
    dijkstra(graph, start);
    return 0;
}