#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    for(int start = 1; start <= n; ++start) {
        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]) {
                if(v == start) {
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
    
    if(min_cycle != INT_MAX) {
        cout << min_cycle << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}