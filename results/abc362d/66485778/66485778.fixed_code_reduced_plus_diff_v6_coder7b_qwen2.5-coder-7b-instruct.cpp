#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

vector<pii> adj[MAXN];
ll dist[MAXN];

void dijkstra(int src, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();

        if (du > dist[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w + v < dist[v]) {
                dist[v] = dist[u] + w + v;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> adj[i][0].first;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}