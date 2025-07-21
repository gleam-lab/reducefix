#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    dep[start] = 1;
    int res = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dep[v] == 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
            } else if (v != start && dep[v] >= dep[u]) {
                int cycle_length = dep[u] + dep[v] - 1;
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
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Assuming undirected graph
    }

    int min_cycle = -1;
    for (int i = 1; i <= n; i++) {
        memset(dep, 0, sizeof(dep));
        int cycle = bfs(i);
        if (cycle != -1) {
            if (min_cycle == -1 || cycle < min_cycle) {
                min_cycle = cycle;
            }
            if (min_cycle == 3) break; // Shortest possible cycle
        }
    }

    cout << min_cycle << '\n';
    return 0;
}