#include<iostream>
#include<vector>
#include<algorithm>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1e9 + 7

using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int visited[N], dist[N];

bool dfs(int u, int parent, int& min_cycle) {
    visited[u] = 1;
    dist[u] = parent;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u, min_cycle)) {
                return true;
            }
        } else if (v != parent) {
            min_cycle = min(min_cycle, dist[u] - dist[v] + 1);
            return true;
        }
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = INF;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, 0, min_cycle)) {
                break;
            }
        }
    }

    if (min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

signed main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}