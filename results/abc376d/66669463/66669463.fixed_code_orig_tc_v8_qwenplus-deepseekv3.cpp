#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    vector<int> dist(n+1);
    queue<int> q;
    
    for (int neighbor : adj[1]) {
        if (neighbor == 1) {
            min_cycle = 1;
            break;
        }
        dist.assign(n+1, INT_MAX);
        dist[neighbor] = 1;
        q.push(neighbor);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if (min_cycle == 2) break; // can't get shorter than 2
        }
        if (min_cycle == 2) break; // early exit if found shortest possible
    }
    
    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }
    
    return 0;
}