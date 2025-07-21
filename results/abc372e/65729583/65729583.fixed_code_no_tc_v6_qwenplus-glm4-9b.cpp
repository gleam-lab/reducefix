#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 2e5 + 9;

int parent[N];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        parent[v] = u;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    vector<vector<int>> adjList(N + 1);
    vector<int> results;
    
    int u, v, k;
    while (q--) {
        cin >> u;
        if (u == 1) {
            cin >> v;
            unionSets(u, v);
        } else {
            cin >> v >> k;
            vector<int> connectedVertices;
            for (int neighbor : adjList[v]) {
                if (find(neighbor) == find(v)) {
                    connectedVertices.push_back(neighbor);
                }
            }
            if (k > connectedVertices.size()) {
                results.push_back(-1);
            } else {
                sort(connectedVertices.begin(), connectedVertices.end());
                results.push_back(connectedVertices[connectedVertices.size() - k]);
            }
        }
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}