#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INT signed

constexpr int INF = 1e18;

struct Node {
    int x;
    long long w;
    bool operator < (const Node& other) const {
        return w > other.w; // Min-heap based on distance
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pair<int, int>>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V, B;
        cin >> U >> V >> B;
        g[U].emplace_back(V, B);
        g[V].emplace_back(U, B);
    }
    
    vector<long long> dist(N + 1, INF);
    vector<bool> visited(N + 1, false);
    priority_queue<Node> pq;
    
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.x;
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto& edge : g[u]) {
            int v = edge.first;
            int cost = edge.second;
            if (dist[v] > dist[u] + cost + A[v]) {
                dist[v] = dist[u] + cost + A[v];
                pq.push({v, dist[v]});
            }
        }
    }
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }
}

INT main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}