#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<int> adj[200005];

// BFS function to find shortest cycle length starting from node 1
ll bfs() {
    vector<ll> dist(200005, -1);
    queue<ll> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (v == 1) {
                // We found a cycle back to node 1
                return dist[u] + 1;
            }
        }
    }
    
    return -1; // No cycle found
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // Find shortest cycle that starts and ends at node 1
    ll result = -1;
    
    // Try all possible starting edges from node 1
    for (int start_node : adj[1]) {
        vector<ll> dist(200005, -1);
        queue<ll> q;
        
        dist[1] = 0;
        dist[start_node] = 1;
        q.push(start_node);
        
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            
            for (ll v : adj[u]) {
                if (v == 1) {
                    // Found a cycle back to 1
                    if (result == -1 || dist[u] + 1 < result) {
                        result = dist[u] + 1;
                    }
                    break;
                }
                
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cout << result << endl;
    return 0;
}