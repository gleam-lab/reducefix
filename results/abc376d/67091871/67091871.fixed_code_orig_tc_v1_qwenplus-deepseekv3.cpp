#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005;
vector<int> b[200005];
ll vis[200005];
ll dist[200005];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : b[u]) {
            if(v == start) {
                mn = min(mn, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    
    memset(dist, -1, sizeof(dist));
    bfs(1);
    
    if(mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}