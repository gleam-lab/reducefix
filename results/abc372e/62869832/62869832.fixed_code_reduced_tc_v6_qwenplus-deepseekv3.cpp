#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> top[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return;

    if (top[rootU].size() < top[rootV].size()) {
        swap(rootU, rootV);
    }

    vector<int> merged;
    merge(top[rootU].begin(), top[rootU].end(),
          top[rootV].begin(), top[rootV].end(),
          back_inserter(merged));
    sort(merged.rbegin(), merged.rend());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top[rootU] = merged;
    parent[rootV] = rootU;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (top[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }

    return 0;
}