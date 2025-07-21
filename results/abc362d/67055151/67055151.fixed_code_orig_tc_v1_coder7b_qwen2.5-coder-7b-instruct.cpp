#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<int> dist(n, INF);
    dist[0] = a[0];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(a[0], 0);

    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if(cost > dist[u]) continue;

        for(auto [v, weight] : adj[u]) {
            int new_cost = cost + a[v] + weight;
            if(new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    for(int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}