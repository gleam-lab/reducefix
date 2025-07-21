#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define INT i64
#define INF 1e18
vector<pair<int, int>> adj[200001];
vector<INT> dist(200001, INF);

void dijkstra(int start) {
    priority_queue<pair<INT, int>, vector<pair<INT, int>>, greater<pair<INT, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [curr_dist, u] = pq.top();
        pq.pop();

        if (curr_dist > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            INT new_dist = curr_dist + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    INT n, m;
    cin >> n >> m;
    vector<INT> a(n + 1);
    for (INT i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (INT i = 0; i < m; ++i) {
        INT u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    dijkstra(1);

    for (INT i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}