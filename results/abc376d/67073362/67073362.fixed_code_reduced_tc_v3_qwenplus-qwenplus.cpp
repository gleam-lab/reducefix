#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
using namespace std;

const int N = 2e5 + 10, INF = 1e9 + 7;
vector<int> adj[N];

int bfs(int n) {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return (dist[n] == INF ? -1 : dist[n]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    
    cout << bfs(n) << endl;
}

signed main() {
    IOS;
    solve();
    return 0;
}