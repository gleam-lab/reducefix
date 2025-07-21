#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<int> adj[200005];
ll dist[200005];

void bfs() {
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (ll i = 1; i <= n; ++i) {
        dist[i] = -1;
    }
    
    for (ll i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    bfs();
    
    if (dist[n] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    
    return 0;
}