#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

void bfs() {
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (v == 1 && d + 1 < ans) {
                ans = d + 1;
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    bfs();
    if (ans != (int)1e18) cout << ans;
    else cout << -1;
    return 0;
}