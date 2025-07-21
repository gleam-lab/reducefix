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
    
    // Perform BFS for each neighbor of node 1
    for (int neighbor : adj[1]) {
        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(neighbor);
        dist[neighbor] = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if (min_cycle == 3) break; // Early exit if we find the smallest possible cycle
        }
        if (min_cycle == 3) break; // Early exit if we find the smallest possible cycle
    }

    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }

    return 0;
}