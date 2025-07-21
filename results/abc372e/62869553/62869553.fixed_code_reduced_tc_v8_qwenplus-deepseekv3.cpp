#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> top_k[MAXN];

int find_set(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    if (top_k[u].size() < top_k[v].size()) swap(u, v);
    parent[v] = u;
    top_k[u].insert(top_k[u].end(), top_k[v].begin(), top_k[v].end());
    sort(top_k[u].rbegin(), top_k[u].rend());
    if (top_k[u].size() > K) top_k[u].resize(K);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_k[i].push_back(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (v > (int)top_k[root].size()) {
                cout << "-1\n";
            } else {
                cout << top_k[root][v - 1] << "\n";
            }
        }
    }

    return 0;
}