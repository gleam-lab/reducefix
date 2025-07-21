#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], parent[N];

int bfs() {
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    parent[1] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (v == parent[u]) continue;
            if (dep[v] == 0) {
                dep[v] = dep[u] + 1;
                parent[v] = u;
                q.push(v);
            } else {
                return dep[u] + dep[v] - 1;
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