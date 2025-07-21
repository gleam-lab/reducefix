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
    
    for (int u = 1; u <= n; ++u) {
        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int v : adj[current]) {
                if (v == u) {  // Found a cycle back to u
                    min_cycle = min(min_cycle, dist[current] + 1);
                    break;
                }
                if (dist[v] == -1) {
                    dist[v] = dist[current] + 1;
                    q.push(v);
                }
            }
            if (min_cycle == 2) break;  // Can't get shorter than 2
        }
        if (min_cycle == 2) break;  // Early exit if smallest possible found
    }
    
    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }
    
    return 0;
}