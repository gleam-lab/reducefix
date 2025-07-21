#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int n, m;

int findShortestCycle() {
    int ans = INF;
    for (int start : g[1]) {
        queue<pair<int, int>> q;
        vector<int> dist(n + 1, INF);
        dist[start] = 1;
        q.push({start, 1});
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();
            if (u == 1) {
                ans = min(ans, d);
                break;
            }
            for (int v : g[u]) {
                if (dist[v] > d + 1) {
                    dist[v] = d + 1;
                    q.push({v, d + 1});
                }
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