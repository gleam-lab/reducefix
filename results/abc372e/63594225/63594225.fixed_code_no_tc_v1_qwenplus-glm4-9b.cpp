#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<vector<int>> graph;
vector<set<int>> adjVertices;
vector<int> verticesSorted;
vector<bool> visited;

int find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void unite(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        parent[v] = u;
        adjVertices[u].insert(v);
        adjVertices[v].insert(u);
    }
}

void addEdge(int u, int v) {
    if (!adjVertices[u].count(v)) {
        adjVertices[u].insert(v);
        adjVertices[v].insert(u);
    }
}

void dfs(int v) {
    visited[v] = true;
    verticesSorted.push_back(v);
    for (int next : adjVertices[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    graph.resize(n + 1);
    adjVertices.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            if (find_set(u) != find_set(v)) {
                unite(u, v);
            }
        } else if (type == 2) {
            int root = find_set(v);
            if (adjVertices[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << verticesSorted[adjVertices[root].size() - v] << '\n';
            }
        }
    }

    return 0;
}