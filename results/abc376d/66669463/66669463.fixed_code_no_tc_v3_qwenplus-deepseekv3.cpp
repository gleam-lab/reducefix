#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> dist(n+1, INT_MAX);
    queue<pair<int, int>> q; // {node, parent}
    
    // Start BFS from node 1
    dist[1] = 0;
    q.push({1, -1});
    
    int min_cycle = INT_MAX;
    
    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1 && u != parent) { // Found a cycle back to 1
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }
    
    if (min_cycle != INT_MAX) {
        cout << min_cycle << '\n';
    } else {
        cout << "-1\n";
    }
    
    return 0;
}