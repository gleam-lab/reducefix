#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
vector<int> parent(MAX_N);
vector<vector<int>> top_elements(MAX_N);

int find_root(int x) {
    if (parent[x] != x) {
        parent[x] = find_root(parent[x]);
    }
    return parent[x];
}

void merge(int u, int v) {
    int root_u = find_root(u);
    int root_v = find_root(v);
    if (root_u == root_v) return;

    if (top_elements[root_u].size() < top_elements[root_v].size()) {
        swap(root_u, root_v);
    }

    vector<int> merged;
    merge(top_elements[root_u].begin(), top_elements[root_u].end(),
          top_elements[root_v].begin(), top_elements[root_v].end(),
          back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top_elements[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
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
            merge(u, v);
        } else {
            int root = find_root(u);
            if (v > (int)top_elements[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top_elements[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}