#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int parent[N + 1];
vector<int> size(N + 1);
vector<int> graph[N + 1];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        merge(graph[u].begin(), graph[u].end(), graph[v].begin(), graph[v].end());
    }
}

void addEdge(int u, int v) {
    if (find(u) != find(v)) {
        unionSets(u, v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            addEdge(u, v);
        } else {
            auto& neighbors = graph[find(v)];
            if (neighbors.size() < v) {
                cout << -1 << '\n';
            } else {
                cout << neighbors.back() << '\n';
                neighbors.pop_back();
            }
        }
    }
    return 0;
}