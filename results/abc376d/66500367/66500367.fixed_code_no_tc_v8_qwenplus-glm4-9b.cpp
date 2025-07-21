#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], par[N];

int bfs() {
    queue<pii> q;
    q.push({1, 0});
    par[1] = 0; // Root node parent is 0
    dep[1] = 1;

    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        for (int v : g[u]) {
            if (v != p) {
                if (dep[v]) {
                    // If v already has depth, check for cycle
                    if (dep[v] < dep[u]) {
                        // Cycle detected, return the size of the cycle
                        int cycle_size = dep[u] - dep[v] + 1;
                        int cycle_node = v;
                        while (cycle_node != u) {
                            cycle_node = par[cycle_node];
                            cycle_size++;
                        }
                        return cycle_size;
                    }
                } else {
                    // No cycle detected, continue BFS
                    dep[v] = dep[u] + 1;
                    par[v] = u;
                    q.push({v, u});
                }
            }
        }
    }
    return -1; // No cycle found
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
    }

    cout << bfs() << '\n';
    return 0;
}