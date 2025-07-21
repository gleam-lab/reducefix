#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_k[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger to optimize path compression
    if (top_k[pu].size() < top_k[pv].size())
        swap(pu, pv);

    // Merge top_k lists
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top_k[pu].size() && j < top_k[pv].size() && merged.size() < K_MAX) {
        if (top_k[pu][i] > top_k[pv][j])
            merged.push_back(top_k[pu][i++]);
        else
            merged.push_back(top_k[pv][j++]);
    }

    while (i < top_k[pu].size() && merged.size() < K_MAX)
        merged.push_back(top_k[pu][i++]);

    while (j < top_k[pv].size() && merged.size() < K_MAX)
        merged.push_back(top_k[pv][j++]);

    top_k[pu] = merged;
    parent[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_k[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= top_k[root].size())
                cout << top_k[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}