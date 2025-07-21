#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph for cycle detection
    }

    queue<pair<int, int>> q; // {node, parent}
    vector<int> dist(n + 1, -1);
    q.push({1, -1});
    dist[1] = 0;
    int min_cycle = INT_MAX;

    while (!q.empty()) {
        auto [current, parent] = q.front();
        q.pop();
        for (int neighbor : adj[current]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push({neighbor, current});
            } else if (neighbor != parent && neighbor == 1) {
                min_cycle = min(min_cycle, dist[current] + 1);
            }
        }
    }

    if (min_cycle == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }

    return 0;
}