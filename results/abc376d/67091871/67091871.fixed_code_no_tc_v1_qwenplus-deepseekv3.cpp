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

    queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    q.push({1, 0});
    dist[1] = 0;
    ll min_cycle = LLONG_MAX;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int u = current.first;
        int current_dist = current.second;

        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, (ll)current_dist + 1);
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = current_dist + 1;
                q.push({v, dist[v]});
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