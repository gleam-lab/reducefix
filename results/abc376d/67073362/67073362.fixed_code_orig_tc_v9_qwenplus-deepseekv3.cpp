#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    
    // Perform BFS from node 1 to find shortest cycle containing it
    for (int neighbor : adj[1]) {
        queue<pair<int, int>> q;
        vector<int> dist(n+1, -1);
        q.push({neighbor, 1});
        dist[neighbor] = 1;
        
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, d + 1);
                    continue;
                }
                if (dist[v] == -1) {
                    dist[v] = d + 1;
                    q.push({v, d + 1});
                }
            }
        }
    }
    
    if (min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
    
    return 0;
}