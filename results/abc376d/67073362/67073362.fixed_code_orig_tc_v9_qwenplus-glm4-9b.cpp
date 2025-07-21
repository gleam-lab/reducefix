#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, INF = numeric_limits<int>::max(), P = 998244353;
vector<int> a[N];
int dist[N];
int mi = INF;

void dfs(int u, int deep) {
    if (dist[u] < deep) {
        return;
    }
    for (auto i : a[u]) {
        dfs(i, deep + 1);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u); // Ensure bidirectional edges
    }
    fill(dist, dist + N, INF);
    dist[1] = 0;
    dfs(1, 0);
    if (mi == INF) {
        cout << -1 << endl;
    } else {
        cout << mi << endl;
    }
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}