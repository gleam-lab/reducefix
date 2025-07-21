#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define PII pair<int, int>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10, INF = 1e9 + 7;

vector<vector<int>> adj;
vector<int> dist;
int n, m;

void bfs() {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(1);
    visited[1] = true;
    int level = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int u = q.front(); q.pop();
            if (u == 1 && level > 0) {
                cout << level;
                return;
            }
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        level++;
    }
    cout << -1;
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs();
}

signed main() {
    IOS;
    int T = 1;
    while (T--) solve();
    return 0;
}