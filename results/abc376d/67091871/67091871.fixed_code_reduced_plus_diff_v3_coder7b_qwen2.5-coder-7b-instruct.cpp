#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
bool vis[MAXN];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (auto v : g[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int connectedComponents = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++connectedComponents;
        }
    }

    cout << connectedComponents - 1 << '\n';

    return 0;
}