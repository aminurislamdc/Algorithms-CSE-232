#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, src;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[100];
    int dist[100];

    cout << "Enter source, destination and weight:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    cout << "Enter source vertex: ";
    cin >> src;
    for (int i = 0; i < V; i++) {
        dist[i] = 1e9;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle!\n";
            return 0;
        }
    }

    cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << "\n";
    }

    return 0;
}
