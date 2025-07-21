#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = -1;
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    // BFS from node 1 to find the shortest cycle back to 1
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                // Found a cycle back to 1
                if(min_cycle == -1 || dist[u] + 1 < min_cycle) {
                    min_cycle = dist[u] + 1;
                }
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    cout << min_cycle << endl;
    return 0;
}