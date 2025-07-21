#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll min_cycle = LLONG_MAX;
    queue<pair<int, ll>> q;
    vector<ll> dist(n + 1, -1);

    // Start BFS from node 1
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
        auto [current, d] = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (neighbor == 1) {
                // Found a cycle back to node 1
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if (dist[neighbor] == -1) {
                dist[neighbor] = d + 1;
                q.push({neighbor, d + 1});
            }
        }
    }

    if (min_cycle == LLONG_MAX) {
        cout << -1;
    } else {
        cout << min_cycle;
    }

    return 0;
}