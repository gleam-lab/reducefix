#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

typedef pair<LL, int> PII;

struct Graph {
    int n;
    vector<vector<pair<int, LL>>> adj;

    Graph(int _n) : n(_n), adj(_n) {}

    void addEdge(int u, int v, LL w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<LL> dijkstra(int start) {
        vector<LL> dist(n, INF);
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                LL new_dist = d + w + dist[u];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Graph g(n + 1);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    vector<LL> result = g.dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}