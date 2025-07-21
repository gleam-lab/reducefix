#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs(int start) {
    memset(dep, -1, sizeof(dep));
    queue<pii> q;
    q.push({start, -1});
    dep[start] = 0;
    int res = -1;
    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            if (v == p) continue;
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                q.push({v, u});
            } else {
                int cycle_length = dep[u] + dep[v] + 1;
                if (res == -1 || cycle_length < res) {
                    res = cycle_length;
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        int current = bfs(i);
        if (current != -1) {
            if (ans == -1 || current < ans) {
                ans = current;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}