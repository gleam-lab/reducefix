#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pair<int, long long>>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u - 1].emplace_back(v - 1, b);
        graph[v - 1].emplace_back(u - 1, b);
    }
    
    vector<long long> dist(N, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    pq.push({A[0], 0});
    dist[0] = A[0];
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, weight] : graph[u]) {
            long long newDist = d + weight + A[v];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << (i < N - 1 ? " " : "\n");
    }
    
    return 0;
}