#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> parent(MAXN);
vector<vector<int>> top(MAXN);

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

    parent[rootV] = rootU;
    top[rootU].insert(top[rootU].end(), top[rootV].begin(), top[rootV].end());
    sort(top[rootU].rbegin(), top[rootU].rend());
    if (top[rootU].size() > 10) {
        top[rootU].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }

    return 0;
}