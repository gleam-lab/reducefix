#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;

int bfs(int start) {
    vector<int> dep(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    dep[start] = 0;
    int min_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (v != parent[u]) {
                min_cycle = min(min_cycle, dep[u] + dep[v] + 1);
            }
        }
    }

    return min_cycle == INT_MAX ? -1 : min_cycle;
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

    int min_cycle = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int cycle = bfs(i);
        if (cycle != -1) {
            min_cycle = min(min_cycle, cycle);
        }
    }

    cout << (min_cycle == INT_MAX ? -1 : min_cycle) << '\n';
    return 0;
}