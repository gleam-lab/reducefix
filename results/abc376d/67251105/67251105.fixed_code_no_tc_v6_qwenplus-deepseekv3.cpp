#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    
    vector<int> dist(N, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int ans = INF;
    for(int u = 0; u < N; u++) {
        if(dist[u] == -1) continue;
        for(int v : G[u]) {
            if(v == 0) {
                ans = min(ans, dist[u] + 1);
            }
        }
    }
    
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}