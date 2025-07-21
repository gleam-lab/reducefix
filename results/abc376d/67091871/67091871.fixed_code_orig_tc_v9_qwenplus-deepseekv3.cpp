#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<int> b[200005];
ll dist[200005];

ll bfs() {
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    q.push(1);
    
    ll min_cycle = 1e9;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : b[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return min_cycle == 1e9 ? -1 : min_cycle;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    
    ll result = bfs();
    cout << result << endl;
    
    return 0;
}