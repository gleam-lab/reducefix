#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs() {
    queue<array<int, 2>> q;
    q.push({1, 0});
    dep[1] = 1;
    while (!q.empty()) {
        auto [u, p] = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (v != p) {
                if (dep[v]) return dep[u];
                dep[v] = dep[u] + 1;
                q.push({v, u});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << bfs() << '\n';
    return 0;
}