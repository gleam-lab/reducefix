#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

struct Edge {
    int to;
    i64 cost;
};

struct Node {
    int vertex;
    i64 cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
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
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    vector<i64> dist(N + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;
        i64 current_dist = node.cost;
        
        if (current_dist > dist[u]) continue;
        
        for (const Edge& e : adj[u]) {
            int v = e.to;
            i64 new_dist = current_dist + e.cost + A[v];
            
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
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