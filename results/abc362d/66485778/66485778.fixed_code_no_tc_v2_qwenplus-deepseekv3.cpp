#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Node {
    int x;
    ll w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

vector<pair<int, ll>> g[200005];
ll dist[200005];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[i].clear();
        dist[i] = INF;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.x;
        ll current_dist = node.w;

        if (current_dist > dist[u]) continue;

        for (auto [v, b] : g[u]) {
            ll new_dist = dist[u] + b + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}