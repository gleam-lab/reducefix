#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
const i64 INF = 1e18;

struct Node {
    int node;
    i64 cost;
    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    
    vector<vector<pii>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // path weight = vertex weight A[u] and A[v] are already accounted in d[]
        // edge weight is added to the path
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    priority_queue<Node> pq;
    vector<i64> d(N + 1, INF);
    d[1] = A[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [u, cost] = pq.top();
        pq.pop();

        if (cost > d[u]) continue;

        for (const auto& [v, w] : graph[u]) {
            if (d[u] + w + A[v] < d[v]) {
                d[v] = d[u] + w + A[v];
                pq.push({v, d[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << d[i] << " ";
    cout << "\n";

    return 0;
}