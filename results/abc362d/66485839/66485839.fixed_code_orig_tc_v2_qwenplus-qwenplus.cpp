#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int MAXN = 2e5 + 5;
const i64 INF = 1e18;

int N, M;
vector<i64> A;
vector<vector<pii>> adj;

void solve() {
    cin >> N >> M;
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    
    adj.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<i64> dist(N + 1, INF);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;

    dist[1] = A[1];
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, b] : adj[u]) {
            if (dist[v] > d + b + A[v]) {
                dist[v] = d + b + A[v];
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << dist[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}