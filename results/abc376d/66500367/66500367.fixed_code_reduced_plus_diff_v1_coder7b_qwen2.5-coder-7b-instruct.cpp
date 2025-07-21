#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
bool vis[N], color[N];

bool dfs(int u, int c) {
    color[u] = c;
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            if (!dfs(v, !c)) return false;
        } else if (color[v] == color[u]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool isBipartite = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 0)) {
                isBipartite = false;
                break;
            }
        }
    }

    cout << (isBipartite ? "1" : "-1") << '\n';

    return 0;
}