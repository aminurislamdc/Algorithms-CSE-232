#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class BellmanFord {
private:
    int V;
    vector<vector<int>> matrix;

public:
    BellmanFord(const vector<vector<int>>& adjMatrix)
        : V(adjMatrix.size()), matrix(adjMatrix) {}

    vector<long long> compute(int src) {
        const long long INF = numeric_limits<long long>::max();
        vector<long long> dist(V + 1, INF);
        vector<int> count(V + 1, 0);
        vector<bool> in_q(V + 1, false);
        queue<int> q;

        dist[src] = 0; q.push(src); in_q[src] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            in_q[u] = false;

            for (int v = 1; v <= V; ++v) {
                int weight = matrix[u - 1][v - 1];

                if (u != v && weight > 0) {
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;

                        if (!in_q[v]) {
                            q.push(v);
                            in_q[v] = true;
                            if (++count[v] >= V) return {};
                        }
                    }
                }
            }
        }
        return dist;
    }
};

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 2, 1},
        {0, 0, 3, 2, 0, 5},
        {0, 0, 0, 1, 5, 0}
    };

    BellmanFord graph(adjacencyMatrix);
    auto res = graph.compute(1);

    if (!res.empty()) {
        for (int i = 1; i <= 6; ++i)
            cout << i << " -> " << res[i] << "\n";
    }
    return 0;
}
