#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs(int start) {
    queue<pii> q;
    q.push({start, 0});
    dep[start] = 1;
    while (!q.empty()) {
        auto [u, p] = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (v == p) continue; // Skip the parent node
            if (dep[v]) { // Node already visited
                return dep[u] + dep[v]; // Return the length of the cycle
            }
            dep[v] = dep[u] + 1;
            q.push({v, u});
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
        g[v].push_back(u); // Since it's an undirected graph
    }

    int min_cycle = INT_MAX;
    bool found_cycle = false;

    for (int i = 1; i <= n; i++) {
        memset(dep, 0, sizeof(dep));
        int cycle_length = bfs(i);
        if (cycle_length != -1) {
            found_cycle = true;
            min_cycle = min(min_cycle, cycle_length);
        }
    }

    if (found_cycle) {
        cout << min_cycle << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}