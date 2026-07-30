#include <iostream>
#include <queue>
using namespace std;

void bfs(int n, int adj[100][100], int src) {
    bool vis[100] = {false};
    queue<int> q;
    vis[src] = true; q.push(src);
    cout << "BFS Traversal:\n";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !vis[v]) vis[v] = true, q.push(v);
    }
    cout << "\n";
}

int main() {
    int n, src, adj[100][100];
    cout << "Enter number of vertices:\n"; cin >> n;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> adj[i][j];
    cout << "Enter source vertex:\n"; cin >> src;
    bfs(n, adj, src);
}
