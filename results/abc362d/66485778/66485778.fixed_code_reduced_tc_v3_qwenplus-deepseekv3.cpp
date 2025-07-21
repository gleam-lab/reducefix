#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INT signed
#define pbk push_back

template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int64_t distance;
    bool operator < (const Node& other) const {
        return distance > other.distance;
    }
};

const int64_t INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    VV<Edge> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }
    V<int64_t> dist(n + 1, INF);
    V<bool> visited(n + 1, false);
    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.push({1, dist[1]});
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;
        if (visited[u]) continue;
        visited[u] = true;
        for (const Edge& edge : g[u]) {
            int v = edge.to;
            int64_t new_dist = dist[u] + edge.weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " \n"[i == n];
    }
}

INT main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}