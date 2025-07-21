#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, i64>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        i64 B;
        cin >> U >> V >> B;
        graph[U].emplace_back(V, B);
        graph[V].emplace_back(U, B);
    }

    priority_queue<Node> pq;
    vector<i64> dist(N + 1, INF);
    dist[1] = A[1]; // Start from vertex 1 with its own weight
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, b]: graph[u]) {
            i64 new_dist = d + b + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}