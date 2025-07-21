#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 INF = 1e18;

struct Edge {
    int to;
    i64 cost;
};

struct Node {
    int vertex;
    i64 dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<Edge>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].push_back({v, b + A[v]});
        g[v].push_back({u, b + A[u]});
    }
    
    vector<i64> dist(N + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;
        i64 d = node.dist;
        
        if (d > dist[u]) continue;
        
        for (const Edge& e : g[u]) {
            int v = e.to;
            i64 cost = e.cost;
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({v, dist[v]});
            }
        }
    }
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " \n"[i == N];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}