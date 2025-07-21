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
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    // For each neighbor of node 1, perform BFS to find shortest path back to 1
    for (int neighbor : adj[1]) {
        if (neighbor == 1) {
            min_cycle = 1;
            break;
        }
        
        queue<pair<int, int>> q;
        q.push({neighbor, 1});
        vector<bool> visited(n + 1, false);
        visited[neighbor] = true;
        
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            
            if (node == 1) {
                min_cycle = min(min_cycle, dist + 1);
                break;
            }
            
            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, dist + 1});
                }
            }
        }
    }
    
    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }
    
    return 0;
}