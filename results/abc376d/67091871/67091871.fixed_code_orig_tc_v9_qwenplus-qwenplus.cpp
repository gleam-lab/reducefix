#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN = 200005;
ll n, m;
vector<ll> adj[MAXN];
ll dist[MAXN];

void bfs() {
    queue<ll> q;
    for (ll i = 1; i <= n; ++i) {
        dist[i] = -1;
    }

    // Start from node 1 with distance 0
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bfs();

    cout << (dist[n] != -1 ? dist[n] : -1) << "\n";

    return 0;
}