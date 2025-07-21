#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int n, m;

int findShortestCycle() {
    int ans = INF;
    for (int start = 1; start <= n; ++start) {
        vector<int> dist(n + 1, INF);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v && parent[v] != u) {
                    ans = min(ans, dist[u] + dist[v] + 1);
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
        g[v].push_back(u); // Assuming undirected graph; remove if directed
    }
    int result = findShortestCycle();
    cout << result << endl;
    return 0;
}