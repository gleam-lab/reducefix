#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    vector<int> dist(n+1);
    queue<int> q;
    
    // Perform BFS from each neighbor of node 1
    for(int neighbor : adj[1]) {
        fill(dist.begin(), dist.end(), -1);
        q = queue<int>();
        
        q.push(neighbor);
        dist[neighbor] = 1;
        
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
    
    if(min_cycle != INT_MAX)
        cout << min_cycle << endl;
    else
        cout << -1 << endl;
    
    return 0;
}