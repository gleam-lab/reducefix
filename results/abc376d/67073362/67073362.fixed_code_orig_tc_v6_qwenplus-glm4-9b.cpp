#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

vector<int> a[N];

int mi = 1e9, g[N], dist[N];

void dfs(int u, int deep) {
    g[u] = 1;
    dist[u] = deep;
    for (auto i : a[u]) {
        if (!g[i]) {
            dfs(i, deep + 1);
            mi = min(mi, dist[i]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u); // Ensure undirected graph
    }
    dfs(1, 0);
    if (mi == 1e9) {
        cout << -1 << endl;
    } else {
        cout << mi << endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}