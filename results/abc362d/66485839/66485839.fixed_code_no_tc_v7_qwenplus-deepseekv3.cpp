#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int id;
    ll dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    vector<ll> dist(N + 1, INF);
    priority_queue<Node> pq;
    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.id;
        ll d = node.dist;
        if (d > dist[u]) continue;

        for (const Edge& e : g[u]) {
            int v = e.to;
            ll cost = e.cost;
            if (dist[v] > dist[u] + cost + A[v]) {
                dist[v] = dist[u] + cost + A[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }

    return 0;
}