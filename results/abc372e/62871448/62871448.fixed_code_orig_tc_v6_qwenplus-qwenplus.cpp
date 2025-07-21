#include <bits/stdc++.h>
using namespace std;

const int K = 10;
int parent[200005];
vector<int> top_nodes[200005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (top_nodes[pu].size() < top_nodes[pv].size())
        swap(pu, pv);

    // Merge top 10 of pv into pu
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top_nodes[pu].size() && j < top_nodes[pv].size() && merged.size() < K) {
        if (top_nodes[pu][i] > top_nodes[pv][j])
            merged.push_back(top_nodes[pu][i++]);
        else
            merged.push_back(top_nodes[pv][j++]);
    }
    while (i < top_nodes[pu].size() && merged.size() < K)
        merged.push_back(top_nodes[pu][i++]);
    while (j < top_nodes[pv].size() && merged.size() < K)
        merged.push_back(top_nodes[pv][j++]);

    top_nodes[pu] = merged;
    parent[pv] = pu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_nodes[i] = {i};
    }

    for (int q = 0; q < Q; ++q) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= top_nodes[root].size())
                cout << top_nodes[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}