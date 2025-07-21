#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int64_t distance;
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V, B;
        cin >> U >> V >> B;
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    priority_queue<Node> pq;
    vector<int64_t> dist(N + 1, LLONG_MAX);
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        if (current.distance > dist[u]) continue;
        
        for (const Edge& e : graph[u]) {
            int v = e.to;
            int64_t new_dist = dist[u] + e.weight + A[v];
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}