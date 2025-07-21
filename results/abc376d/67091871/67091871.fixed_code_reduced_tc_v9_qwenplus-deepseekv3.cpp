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
    }

    vector<ll> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    ll min_cycle = LLONG_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (min_cycle != LLONG_MAX) {
        cout << min_cycle << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}