#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, s;
    cout << "Enter number of vertices: ";
    cin >> n;

    int** g = new int*[n];
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        g[i] = new int[n];
        for(int j = 0; j < n; j++) cin >> g[i][j];
    }

    cout << "Enter starting vertex: ";
    cin >> s;

    stack<int> st;
    bool* v = new bool[n]();
    st.push(s);

    cout << "DFS Traversal:\n";
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(!v[u]) {
            v[u] = 1;
            cout << u << " ";
            for(int i = n - 1; i >= 0; i--)
                if(g[u][i] && !v[i]) st.push(i);
        }
    }
    cout << "\n";
    return 0;
}
