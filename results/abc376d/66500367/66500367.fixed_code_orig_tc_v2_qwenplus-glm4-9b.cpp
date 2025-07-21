#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs () {
    queue<pii> q;
    q.push({1, 0});
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front().first, p = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            if (v != p) {
                if (dep[v]) {
                    // If we revisit a node that has been visited before, we have found a cycle
                    return dep[u];
                }
                dep[v] = dep[u] + 1;
                q.push({v, u});
            }
        }
    }
    // If we have visited all nodes and found no cycles, return 0
    return 0;
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
        g[v].push_back(u); // Ensure the graph is undirected
    }

    cout << bfs() << '\n';
    return 0;
}