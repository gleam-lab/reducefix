#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 INF = 1e18;

struct Edge {
    int to;
    i64 weight;
};

struct Node {
    int vertex;
    i64 distance;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        i64 B;
        cin >> U >> V >> B;
        adj[U].push_back({V, B});
        adj[V].push_back({U, B});
    }

    vector<i64> dist(N + 1, INF);
    dist[1] = A[1];
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        i64 d = current.distance;

        if (d > dist[u]) continue;

        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            i64 weight = edge.weight;
            if (dist[v] > dist[u] + weight + A[v]) {
                dist[v] = dist[u] + weight + A[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}