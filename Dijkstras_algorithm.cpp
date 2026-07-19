#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinDistance(const vector<int>& distance, const vector<bool>& visited, int V) {
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && distance[v] <= minDistance) {
            minDistance = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(const vector<vector<int>>& graph, int source, int V) {
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);

    distance[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinDistance(distance, visited, V);

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] != 0 && distance[u] != INT_MAX
                && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    cout << "\nExpected Output\n";
    cout << "Shortest distance from source vertex " << (source + 1) << "\n";
    cout << "Vertex\tDistance\n";
    for (int i = 0; i < V; ++i) {
        cout << (i + 1) << "\t" << (distance[i] == INT_MAX ? -1 : distance[i]) << "\n";
    }
}

int main() {
    int V = 6;
    int source = 0;

    vector<vector<int>> graph = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 2, 1},
        {0, 0, 3, 2, 0, 5},
        {0, 0, 0, 1, 5, 0}
    };

    dijkstra(graph, source, V);

    return 0;
}
