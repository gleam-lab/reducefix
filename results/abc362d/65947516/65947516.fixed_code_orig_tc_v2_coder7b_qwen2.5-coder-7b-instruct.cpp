#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back

const int MAXN = 2e5 + 5;
vector<pll> g[MAXN];
ll dist[MAXN];

void dijkstra(int start) {
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({start, 0});
    while (!pq.empty()) {
        auto [node, d] = pq.top(); pq.pop();
        if (dist[node] <= d) continue;
        dist[node] = d;
        for (auto &[neighbor, weight] : g[node]) {
            pq.push({neighbor, d + weight + dist[start]});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
        for (int j = i + 1; j <= n; ++j) {
            cout << dist[j] + a[j] << " ";
        }
        memset(dist, 0x3f, sizeof(dist));
    }

    return 0;
}