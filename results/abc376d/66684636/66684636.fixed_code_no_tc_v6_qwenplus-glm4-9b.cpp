#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
bool vis[N];
int n, m;
int ans = numeric_limits<int>::max();

void dfs(int u, int cnt) {
    vis[u] = true;
    if (cnt >= ans) return;
    if (u == 1) {
        ans = min(ans, cnt);
    } else {
        ans = min(ans, cnt - 1); // Correct the depth calculation
    }
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1, 0);
    if (ans == numeric_limits<int>::max()) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}