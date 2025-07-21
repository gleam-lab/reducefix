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
    for (int start_node : g[1]) {
        queue<int> q;
        fill(dist, dist + N, INF);
        dist[start_node] = 1;
        q.push(start_node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (v == 1) {
                    ans = min(ans, dist[u] + 1);
                    continue;
                }
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
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