#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
vector<int> a[N];
int mi = INF, g[N]; // g should be initialized to 0 or false

// Define DFS function
void dfs(int u, int deep) {
    g[u]++;
    for (auto i : a[u]) {
        if (!g[i]) {
            dfs(i, deep + 1);
        } else {
            mi = min(mi, deep);
        }
    }
}

// Define the solve function
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u); // Assuming undirected graph
    }
    dfs(1, 0); // Start DFS from node 1 with depth 0
    if (mi == INF)
        cout << -1 << endl;
    else
        cout << mi << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}