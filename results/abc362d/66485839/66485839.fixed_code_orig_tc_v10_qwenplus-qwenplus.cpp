#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using Edge = tuple<int, int, long long>;

const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pii>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // The path cost includes edge weight and destination vertex weight
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    // Dijkstra's algorithm with modification:
    // d[i] = min path cost from 1 to i, where path cost includes all vertex weights on the path once.
    // Since each vertex weight is added only once regardless of how many times we pass through it,
    // we can treat the cost as: sum of edge weights along the path + A[1] + A[i]
    // So we initialize distance to A[1], and add A[v] when reaching v
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> d(n + 1, INF);
    d[1] = A[1];
    pq.emplace(d[1], 1);

    while (!pq.empty()) {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (dist_u > d[u]) continue;

        for (auto &[v, w] : graph[u]) {
            long long new_dist = dist_u + w + A[v];
            if (new_dist < d[v]) {
                d[v] = new_dist;
                pq.emplace(d[v], v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}