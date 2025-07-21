#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    vector<int> dist(n+1);
    queue<int> q;
    
    // BFS from node 1's neighbors
    for(int start : adj[1]) {
        fill(dist.begin(), dist.end(), -1);
        dist[start] = 1;
        q.push(start);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]) {
                if(v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    continue;
                }
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    if(min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }
    
    return 0;
}