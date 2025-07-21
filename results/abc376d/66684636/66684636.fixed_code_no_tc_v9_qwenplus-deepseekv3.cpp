#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int n, m;

int findShortestCycle() {
    int min_cycle = INF;
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    
    dist[1] = 0;
    q.push({1, -1});
    
    while (!q.empty()) {
        auto [u, p] = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (v == p) continue;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push({v, u});
            } else if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
        }
    }
    
    return min_cycle == INF ? -1 : min_cycle;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    int ans = findShortestCycle();
    cout << ans << endl;
    
    return 0;
}