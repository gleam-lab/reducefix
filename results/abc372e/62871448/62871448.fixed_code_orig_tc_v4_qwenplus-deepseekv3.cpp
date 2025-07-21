#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<vector<int>> top_elements(MAXN);

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top_elements[u].size() < top_elements[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    vector<int> merged;
    merged.reserve(top_elements[u].size() + top_elements[v].size());
    merge(top_elements[u].begin(), top_elements[u].end(),
          top_elements[v].begin(), top_elements[v].end(),
          back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top_elements[u] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_elements[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (top_elements[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top_elements[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}