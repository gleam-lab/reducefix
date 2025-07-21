#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<long long> dist(n + 1, LONG_LONG_MAX);
    dist[1] = 0; // èµ·ç¹å°èµ·ç¹çæéä¸º 0
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 1}); // ä»¥ (è·ç¦», èç¹) å½¢å¼é
    
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue; // é¿éå¤å¤ç
        for (auto &[v, w] : adj[u]) {
            long long nextDist = d + w + a[v];
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                q.push({nextDist, v});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}