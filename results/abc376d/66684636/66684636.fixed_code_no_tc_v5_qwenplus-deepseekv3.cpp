#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int n, m;

int find_min_cycle() {
    int min_cycle = INF;
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, INF);
    
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if (dist[v] > d + 1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
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
    
    int ans = find_min_cycle();
    cout << ans << endl;
    
    return 0;
}