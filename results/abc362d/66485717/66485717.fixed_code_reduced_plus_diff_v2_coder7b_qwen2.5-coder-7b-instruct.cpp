#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
const long long INF = LLONG_MAX / 2;

vector<pair<int, int>> adj[MAXN];
long long dist[MAXN];

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        
        if (du > dist[u])
            continue;
        
        for (auto &[v, w] : adj[u]) {
            long long dv = du + w;
            if (dv < dist[v]) {
                dist[v] = dv;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1] = a[1];
    dijkstra(1);

    for (int i = 2; i <= n; ++i)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}