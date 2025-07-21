#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll ans = -1;
    for (ll neighbor : graph[1]) {
        queue<ll> q;
        vector<ll> dist(n + 1, -1);
        dist[neighbor] = 1;
        q.push(neighbor);
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (ll v : graph[u]) {
                if (v == 1) {
                    ll cycle_length = dist[u] + 1;
                    if (ans == -1 || cycle_length < ans) {
                        ans = cycle_length;
                    }
                }
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}