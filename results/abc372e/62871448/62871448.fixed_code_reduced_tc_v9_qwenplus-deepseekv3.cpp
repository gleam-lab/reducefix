#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> top10[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top10[u].size() < top10[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    merge(top10[u].begin(), top10[u].end(), top10[v].begin(), top10[v].end(), back_inserter(merged));
    sort(merged.rbegin(), merged.rend());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top10[u] = merged;
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top10[i] = {i};
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (top10[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top10[root][v - 1] << "\n";
            }
        }
    }
    return 0;
}