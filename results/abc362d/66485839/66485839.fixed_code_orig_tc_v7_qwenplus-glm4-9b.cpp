#include <bits/stdc++.h>
using namespace std;
#define INT long long

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
            return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<INT> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, INT>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }

    vector<INT> dist(n + 1, INT_MAX);
    priority_queue<pair<INT, int>, vector<pair<INT, int>>, greater<pair<INT, int>>> pq;
    dist[1] = a[1];
    pq.push({a[1], 1});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto& [v, weight] : graph[u]) {
            INT newDist = currentDist + a[v] + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "\n");
    }

    return 0;
}