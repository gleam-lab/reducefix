#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 INF = 1e18;

struct Edge {
    int to;
    i64 cost;
};

struct Node {
    i64 distance;
    int vertex;
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        i64 B;
        cin >> U >> V >> B;
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    vector<i64> dist(N + 1, INF);
    priority_queue<Node> pq;
    dist[1] = A[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        i64 current_dist = current.distance;
        int u = current.vertex;

        if (current_dist > dist[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            i64 cost = edge.cost;
            i64 new_dist = current_dist + cost + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
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