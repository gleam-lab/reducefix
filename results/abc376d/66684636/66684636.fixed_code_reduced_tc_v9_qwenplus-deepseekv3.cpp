#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int dist[N];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    queue<int> q;
    fill(dist, dist + N, -1);
    q.push(1);
    dist[1] = 0;
    int ans = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == 1) {
                if (ans == -1 || dist[u] + 1 < ans) {
                    ans = dist[u] + 1;
                }
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << ans << endl;
    return 0;
}