#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1LL << 60

struct Node {
    int v, dist;
    bool operator<(const Node &other) const {
        return dist > other.dist;
    }
};

vector<pair<int, int>> adj[200005];

void dijkstra(int src, vector<LL> &dist, vector<bool> &visited) {
    priority_queue<Node> pq;
    pq.push({src, 0});
    dist[src] = 0;
    
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        
        if (visited[node.v])
            continue;
        
        visited[node.v] = true;
        
        for (auto &neighbor : adj[node.v]) {
            int next_v = neighbor.first;
            int weight = neighbor.second;
            
            if (!visited[next_v] && dist[next_v] > dist[node.v] + weight + min(node.dist, (LL)weight)) {
                dist[next_v] = dist[node.v] + weight + min(node.dist, (LL)weight);
                pq.push({next_v, dist[next_v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    vector<LL> dist_to_1(n + 1, INF);
    vector<bool> visited(n + 1, false);
    
    dijkstra(1, dist_to_1, visited);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist_to_1[i] << " ";
    }
    cout << "\n";
    
    return 0;
}