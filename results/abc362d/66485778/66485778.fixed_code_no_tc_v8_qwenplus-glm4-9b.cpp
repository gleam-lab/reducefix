#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 10;

vector<int> adj[N];
int dist[N];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (int v : adj[u]) {
            if (d + dist[v] < dist[v]) {
                dist[v] = d + dist[v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "");
    }
    cout << endl;

    return 0;
}