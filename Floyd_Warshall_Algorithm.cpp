#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int dist[100][100]; // Fixed array size for simplicity

    cout << "Enter adjacency matrix (use 9999 for INF):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display Output
    cout << "\nShortest Distance Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
