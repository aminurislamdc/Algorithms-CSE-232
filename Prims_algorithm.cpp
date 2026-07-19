#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

void primsMST(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int src = 0;

    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    vector<int> key(V, 1e9);

    pq.push({0, src});
    key[src] = 0;

    int total_weight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        total_weight += weight;

        if (parent[u] != -1) {
            cout << parent[u] << " - " << u << " (Weight: " << weight << ")\n";
        }

        for (auto& neighbor : adj[u]) {
            int v = neighbor.second;
            int w = neighbor.first;

            if (!inMST[v] && key[v] > w) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\nTotal Minimum Weight of MST: " << total_weight << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});

    adj[0].push_back({6, 3});
    adj[3].push_back({6, 0});

    adj[1].push_back({3, 2});
    adj[2].push_back({3, 1});

    adj[1].push_back({8, 3});
    adj[3].push_back({8, 1});

    adj[1].push_back({5, 4});
    adj[4].push_back({5, 1});

    adj[2].push_back({7, 4});
    adj[4].push_back({7, 2});

    primsMST(V, adj);

    return 0;
}
