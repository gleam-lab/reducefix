#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = -1;

// dist[i] stores the minimum distance from node 1 to node i
int dist[N];

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1 || dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Now check for cycles that start and end at node 1
    for (int v : g[1]) {
        if (v != 1 && dist[v] != -1) {
            if (ans == -1 || dist[v] + 1 < ans)
                ans = dist[v] + 1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    memset(dist, -1, sizeof(dist));
    bfs();

    cout << ans << endl;

    return 0;
}