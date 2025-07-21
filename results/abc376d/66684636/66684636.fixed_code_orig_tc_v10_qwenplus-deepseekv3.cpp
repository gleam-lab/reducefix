#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int n, m;

int findShortestCycle() {
    int ans = INF;
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            if (v == 1) {
                ans = 1;
                break;
            }
        }
        if (ans == 1) break;
    }
    if (ans == 1) return ans;

    queue<int> q;
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == 1) {
                ans = min(ans, dist[u] + 1);
            }
            if (dist[v] == INF) {
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
    int ans = findShortestCycle();
    cout << ans << endl;
    return 0;
}