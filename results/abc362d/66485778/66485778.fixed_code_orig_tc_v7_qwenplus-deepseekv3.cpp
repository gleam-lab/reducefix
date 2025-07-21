#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

struct Edge {
    int to;
    i64 weight;
};

struct Node {
    int vertex;
    i64 distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    
    vector<i64> dist(N + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;
        i64 d = node.distance;
        
        if (d > dist[u]) continue;
        
        for (const Edge& e : graph[u]) {
            int v = e.to;
            i64 new_dist = d + e.weight + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
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