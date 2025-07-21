#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs() {
    queue<pii> q;
    q.push({1, 0});
    dep[1] = 1; // Start from node 1 with depth 1
    while (!q.empty()) {
        int u = q.front().first, p = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            if (v == p) continue; // Skip the parent edge
            if (dep[v] == -1) { // If depth not set, set it and continue BFS
                dep[v] = dep[u] + 1;
                q.push({v, u});
            } else if (dep[v] > 0) { // If depth is already set, we found a cycle
                return dep[u] + dep[v] - 2; // Return the length of the cycle
            }
        }
    }
    return -1; // No cycle found, return -1
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Ensure undirected graph
    }

    cout << bfs() << '\n';
    return 0;
}