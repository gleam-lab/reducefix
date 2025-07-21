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
    
    int min_cycle = INT_MAX;
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    // Initialize BFS from node 1's neighbors
    dist[1] = 0;
    for (int v : adj[1]) {
        if (v == 1) {
            // Self-loop case
            min_cycle = 1;
            break;
        }
        dist[v] = 1;
        q.push(v);
    }
    
    if (min_cycle == 1) {
        cout << "1\n";
        return 0;
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                // Found a cycle back to node 1
                min_cycle = min(min_cycle, dist[u] + 1);
                continue;
            }
            if (dist[v] == -1 || dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    cout << (min_cycle == INT_MAX ? -1 : min_cycle) << "\n";
    return 0;
}