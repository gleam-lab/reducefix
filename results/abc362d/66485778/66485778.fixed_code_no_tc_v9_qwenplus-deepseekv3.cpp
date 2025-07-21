#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Node {
    int x;
    ll w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pair<int, ll>>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    
    vector<ll> dist(N + 1, INF);
    vector<bool> visited(N + 1, false);
    priority_queue<Node> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.x;
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, b] : g[u]) {
            if (dist[v] > dist[u] + b + A[v]) {
                dist[v] = dist[u] + b + A[v];
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