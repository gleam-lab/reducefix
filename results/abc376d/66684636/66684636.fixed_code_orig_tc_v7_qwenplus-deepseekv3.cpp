#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;

int findShortestCycle() {
    int ans = INT_MAX;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
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
    return ans == INT_MAX ? -1 : ans;
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