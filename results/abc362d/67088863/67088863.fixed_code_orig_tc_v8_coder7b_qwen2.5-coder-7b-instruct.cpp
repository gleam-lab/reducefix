#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll INF = LLONG_MAX;

void dijkstra(const vector<vector<pii>>& adj, vector<ll>& dist, int start) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (int i = 0; i < n; ++i) cin >> val[i];

    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjusting indices to zero-based

        adj[u].emplace_back(v, 1LL * w + val[u]);
        adj[v].emplace_back(u, 1LL * w + val[v]);
    }

    vector<ll> dist(n);

    dijkstra(adj, dist, 0);

    for (int i = 1; i < n; ++i) 
        cout << dist[i] + val[i] << " ";

    cout << endl;

    return 0;
}