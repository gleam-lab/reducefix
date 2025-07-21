#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;

vector<int> parent(N + 1);
vector<vector<int>> graph(N + 1);
vector<vector<int>> vertices(N + 1);

void findRoot(int u) {
    if (parent[u] != u) {
        parent[u] = findRoot(parent[u]);
    }
    return parent[u];
}

void unionVertices(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);
    if (u != v) {
        if (vertices[v].size() <= vertices[u].size()) {
            vertices[u].insert(vertices[u].end(), vertices[v].begin(), vertices[v].end());
            sort(vertices[u].rbegin(), vertices[u].rend()); // Sort in descending order
            parent[v] = u;
            vertices[v].clear();
        } else {
            vertices[v].insert(vertices[v].end(), vertices[u].begin(), vertices[u].end());
            vertices[v].erase(unique(vertices[v].begin(), vertices[v].end()), vertices[v].end()); // Remove duplicates
            sort(vertices[v].rbegin(), vertices[v].rend()); // Sort in descending order
            parent[u] = v;
            vertices[u].clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        vertices[i].push_back(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        
        if (t == 1) {
            unionVertices(u, v);
        } else if (t == 2) {
            v = findRoot(v);
            if (vertices[v].size() < v) {
                cout << "-1\n";
            } else {
                cout << vertices[v][v - 1] << '\n'; // v - 1 because vertices are sorted in descending order
            }
        }
    }

    return 0;
}