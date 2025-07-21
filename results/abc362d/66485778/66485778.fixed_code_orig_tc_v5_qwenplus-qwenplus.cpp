#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using Edge = tuple<int, int, long long>;

constexpr int N = 2 * 1e5 + 10;
constexpr long long INF = 1e18;

struct Node {
    int x;
    long long w;
    bool operator<(const Node& other) const {
        return w > other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    priority_queue<Node> pq;
    vector<long long> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    // Start from node 1 with initial cost A[1]
    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, weight] : g[u]) {
            if (!visited[v] && dist[v] > d + weight + A[v]) {
                dist[v] = d + weight + A[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}