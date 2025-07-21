#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

constexpr int MAXN = 2 * 1e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    vector<vector<pair<int, i64>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 B;
        cin >> u >> v >> B;
        graph[u].emplace_back(v, B);
        graph[v].emplace_back(u, B);
    }

    vector<i64> min_dist(N + 1, numeric_limits<i64>::max());
    priority_queue<Node> pq;

    // Start from node 1, distance is A[1] because we include the weight of the starting node
    min_dist[1] = A[1];
    pq.push({1, min_dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > min_dist[u]) continue;

        for (auto [v, edge_cost] : graph[u]) {
            i64 new_cost = d + edge_cost + A[v];
            if (new_cost < min_dist[v]) {
                min_dist[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << min_dist[i] << " ";
    cout << "\n";
}