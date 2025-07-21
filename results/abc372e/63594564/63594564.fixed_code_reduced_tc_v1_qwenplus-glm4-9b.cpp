#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

vector<int> parent(N + 1);
vector<vector<int>> graph(N + 1);

int findRoot(int x) {
    if (parent[x] == x) return x;
    parent[x] = findRoot(parent[x]); // path compression
    return parent[x];
}

void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x != y) {
        // union by rank, not necessary here since k is small
        parent[y] = x;
    }
}

bool inGraph(int x, int y) {
    return findRoot(x) == findRoot(y);
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize parent array as a disjoint set
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            // Union operation
            unite(a, b);
        } else {
            // Find the k-th largest vertex
            if (!inGraph(a, b)) {
                cout << -1 << endl;
            } else {
                vector<int> connectedVertices = graph[findRoot(a)];
                sort(connectedVertices.rbegin(), connectedVertices.rend());
                if (b > connectedVertices.size()) {
                    cout << -1 << endl;
                } else {
                    cout << connectedVertices[b - 1] << endl;
                }
            }
        }

        // Reset graph for next query
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        graph.assign(N + 1, vector<int>());
    }

    return 0;
}