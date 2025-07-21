#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    
    vector<int> dist(N, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int ans = INT_MAX;
    for (int u : G[0]) {
        if (dist[u] != -1) {
            ans = min(ans, dist[u] + 1);
        }
    }
    
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}