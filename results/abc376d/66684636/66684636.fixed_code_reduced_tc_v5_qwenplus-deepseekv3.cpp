#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int n, m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int ans = INF;
    queue<pair<int, int>> q;
    q.push({1, 0});
    dist[1] = 0;
    fill(dist, dist + N, INF);
    dist[1] = 0;

    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();

        for (int v : g[u]) {
            if (v == 1) {
                ans = min(ans, d + 1);
            }
            if (dist[v] > d + 1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }

    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}