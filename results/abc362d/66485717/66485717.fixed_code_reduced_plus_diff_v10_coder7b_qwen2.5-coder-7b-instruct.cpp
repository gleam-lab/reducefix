#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> adj[200005];

void dijkstra(int src, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        
        if (du > dist[u]) continue;
        
        for (auto &e : adj[u]) {
            int v = e.v;
            long long dv = du + e.w;
            
            if (dv < dist[v]) {
                dist[v] = dv;
                pq.push({dv, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n+1, INF);
    dijkstra(1, dist);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}