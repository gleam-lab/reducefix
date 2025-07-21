#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int n, m;

int bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int ans = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == 1) {
                ans = min(ans, dist[u] + 1);
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return ans == INF ? -1 : ans;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dist, -1, sizeof(dist));
    int ans = bfs();
    cout << ans << endl;
    return 0;
}