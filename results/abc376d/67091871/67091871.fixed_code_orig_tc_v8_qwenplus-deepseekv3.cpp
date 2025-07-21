#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = LLONG_MAX;
vector<int> adj[200005];
ll dist[200005];

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;
    
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == start) {
                mn = min(mn, d + 1);
                continue;
            }
            if (dist[v] > d + 1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++) {
        dist[i] = LLONG_MAX;
    }
    
    bfs(1);
    
    if (mn == LLONG_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}