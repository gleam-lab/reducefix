#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5 + 5;

vector<int> g[N];
int n, m, dep[N], vis[N];

int bfs() {
    queue<pii> q;
    q.push({1, 0});
    dep[1] = 1;
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.front().first, d = q.front().second;
        q.pop();
        if (d > 1 && !g[u].size())
            return d - 1;
        for (auto v : g[u]) {
            if (!vis[v]) {
                dep[v] = d + 1;
                vis[v] = 1;
                q.push({v, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Ensure undirected graph
    }

    cout << bfs() << '\n';
    return 0;
}