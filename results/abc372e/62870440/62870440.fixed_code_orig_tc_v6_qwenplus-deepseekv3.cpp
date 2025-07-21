#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<vector<int>> components(MAXN);

void initialize(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].clear();
        components[i].push_back(i);
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    components[u].insert(components[u].end(), components[v].begin(), components[v].end());
    sort(components[u].begin(), components[u].end(), greater<int>());
    if (components[u].size() > 10) {
        components[u].resize(10);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    initialize(N);

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else {
            int k = v;
            u = find(u);
            if (components[u].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << components[u][k - 1] << '\n';
            }
        }
    }

    return 0;
}