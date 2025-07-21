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
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    // BFS from node 1's neighbors
    for (int v : adj[1]) {
        if (v == 1) {
            // Direct self-loop
            min_cycle = 1;
            break;
        }
        
        dist.assign(n+1, -1);
        dist[v] = 1;
        q.push(v);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int neighbor : adj[u]) {
                if (neighbor == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[u] + 1;
                    q.push(neighbor);
                }
            }
        }
    }
    
    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << '\n';
    }
    
    return 0;
}