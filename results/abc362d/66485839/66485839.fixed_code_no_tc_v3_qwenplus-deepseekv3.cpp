#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int vertex;
    ll dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<Edge>> adj(N+1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    vector<ll> dist(N+1, INF);
    vector<bool> visited(N+1, false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (const Edge& e : adj[u]) {
            int v = e.to;
            ll new_dist = dist[u] + e.cost + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
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