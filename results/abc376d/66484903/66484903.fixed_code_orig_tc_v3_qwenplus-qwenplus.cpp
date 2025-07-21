#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

vector<ll> adj[MAXN];
ll dist[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Initialize distances to infinity
    for (ll i = 1; i <= n; ++i) {
        dist[i] = LLONG_MAX;
    }
    dist[1] = 0;

    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (dist[v] == LLONG_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == 1) {
                    cout << dist[v];
                    return 0;
                }
            }
        }
    }

    if (dist[1] == LLONG_MAX)
        cout << -1;
    else
        cout << dist[1];

    return 0;
}