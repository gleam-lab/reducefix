#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int min_cycle = INT_MAX;
    for(int u = 1; u <= n; u++) {
        if(dist[u] != -1) {
            for(int v : adj[u]) {
                if(v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
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