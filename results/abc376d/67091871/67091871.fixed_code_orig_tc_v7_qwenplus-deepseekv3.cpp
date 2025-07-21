#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = LLONG_MAX;
vector<vector<int>> adj;
vector<int> dist;
vector<int> parent;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (v == start && parent[u] != start) {
                mn = min(mn, dist[u] + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    dist.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    bfs(1);
    
    if (mn == LLONG_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    
    return 0;
}