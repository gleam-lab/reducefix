#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 inf = 1e18;

struct Edge {
    int to;
    i64 weight;
    Edge(int to, i64 weight) : to(to), weight(weight) {}
};

struct Node {
    int vertex;
    i64 distance;
    Node(int vertex, i64 distance) : vertex(vertex), distance(distance) {}
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b + a[v]);
        graph[v].emplace_back(u, b + a[u]);
    }
    vector<i64> dist(n + 1, inf);
    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.emplace(1, dist[1]);
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        i64 d = current.distance;
        if (d > dist[u]) continue;
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            i64 new_dist = d + edge.weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(v, dist[v]);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}