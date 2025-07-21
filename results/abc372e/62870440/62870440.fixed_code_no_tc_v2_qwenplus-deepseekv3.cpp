#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> as; // as[i] will store the top 10 largest elements in the component of i's root
vector<int> fa; // parent array for Union-Find

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return;

    if (as[rootU].size() < as[rootV].size()) {
        swap(rootU, rootV);
    }

    vector<int> merged;
    merge(as[rootU].begin(), as[rootU].end(),
          as[rootV].begin(), as[rootV].end(),
          back_inserter(merged), greater<int>());

    if (merged.size() > 10) {
        merged.resize(10);
    }

    as[rootU] = merged;
    fa[rootV] = rootU;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    fa.resize(N + 1);
    as.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        as[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > as[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}