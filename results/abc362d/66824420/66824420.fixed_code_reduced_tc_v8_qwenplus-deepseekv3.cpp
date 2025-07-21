#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.emplace(a[0], 1);

    while (!q.empty()) {
        auto [val, node] = q.top();
        q.pop();
        if (val > dist[node]) continue;
        for (auto [neighbor, weight] : adj[node]) {
            ll new_dist = val + weight + a[neighbor - 1];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                q.emplace(new_dist, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}