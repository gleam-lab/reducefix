#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;
constexpr long long inf = 1e18;

struct Edge {
    int v, w;
    bool operator<(const Edge &other) const { return w > other.w; }
};

vector<Edge> g[N];

void dijkstra(int n, int start) {
    vector<long long> dist(n + 1, inf);
    dist[start] = 0;
    priority_queue<Edge> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : g[u]) {
            long long new_dist = d + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(n, 1);

    return 0;
}