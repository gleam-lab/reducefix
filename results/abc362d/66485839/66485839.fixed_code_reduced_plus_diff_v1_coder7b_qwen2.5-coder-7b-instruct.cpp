#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<pii> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<long long> dist(n+1, INF);
    dist[1] = a[1];
    pq.push({dist[1], 1});

    while(!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if(cost > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            long long new_cost = cost + w + a[v];
            if(new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for(int i=2;i<=n;i++)
        cout << dist[i] << " ";

    return 0;
}