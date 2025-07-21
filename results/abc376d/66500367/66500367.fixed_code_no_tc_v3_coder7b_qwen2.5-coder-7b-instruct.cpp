#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
bool visited[N];

int dfs(int u, int parent, int depth) {
    if (visited[u]) return depth;
    visited[u] = true;
    for (auto v : g[u]) {
        if (v != parent) {
            int result = dfs(v, u, depth + 1);
            if (result != -1) return result;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int result = dfs(i, -1, 0);
            if (result != -1 && i == 1) ans = min(ans, result);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return 0;
}