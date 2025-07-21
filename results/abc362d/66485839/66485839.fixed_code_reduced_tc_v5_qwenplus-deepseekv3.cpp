#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int vertex;
    ll distance;
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap
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

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(N + 1, INF);
    dist[1] = A[1];
    priority_queue<Node> pq;
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        if (current.distance > dist[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            ll cost = edge.cost;
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