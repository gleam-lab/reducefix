#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MAXN = 2e5 + 9;

int parent[MAXN];
set<int> neighbors[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;

    if (neighbors[u].size() > neighbors[v].size())
        swap(u, v);

    for (int neighbor : neighbors[u]) {
        neighbors[v].insert(neighbor);
        if (neighbors[v].size() > 30) {
            neighbors[v].erase(prev(neighbors[v].end()));
        }
    }

    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        neighbors[i].insert(-i);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            v = find(v);

            if (k > neighbors[v].size()) {
                cout << -1 << "\n";
            } else {
                auto it = next(neighbors[v].begin(), k - 1);
                cout << -(*it) << "\n";
            }
        }
    }

    return 0;
}