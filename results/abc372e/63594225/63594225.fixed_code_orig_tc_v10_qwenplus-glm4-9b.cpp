#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
vector<int> parent(N + 1);
vector<vector<int>> graph(N + 1);
vector<vector<int>> sortedAdjacency(N + 1);

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionVertices(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        parent[rootV] = rootU;
        vector<int> adjU = graph[rootU];
        vector<int> adjV = graph[rootV];
        // Combine the adjacency lists
        for (int node : adjV) {
            graph[rootU].push_back(node);
        }
        // Sort the combined adjacency list
        sort(graph[rootU].rbegin(), graph[rootU].rend());
        // Update the sorted adjacency list
        sort(sortedAdjacency[rootU].rbegin(), sortedAdjacency[rootU].rend());
    }
}

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    sortedAdjacency[u].push_back(u);
    sortedAdjacency[v].push_back(v);
    sort(sortedAdjacency[u].rbegin(), sortedAdjacency[u].rend());
    sort(sortedAdjacency[v].rbegin(), sortedAdjacency[v].rend());
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sortedAdjacency[i].push_back(i);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            addEdge(a, b);
        } else {
            int v = find(a);
            if (b > sortedAdjacency[v].size()) {
                cout << -1 << '\n';
            } else {
                cout << sortedAdjacency[v][b - 1] << '\n';
            }
        }
    }
    return 0;
}