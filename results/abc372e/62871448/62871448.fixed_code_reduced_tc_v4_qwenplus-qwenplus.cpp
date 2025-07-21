#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> topNodes[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always merge smaller into larger
    if (topNodes[root_u].size() < topNodes[root_v].size())
        swap(root_u, root_v);

    // Merge top nodes of root_v into root_u
    vector<int> merged;
    auto& list1 = topNodes[root_u];
    auto& list2 = topNodes[root_v];

    int i = 0, j = 0;
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] > list2[j])
            merged.push_back(list1[i++]);
        else
            merged.push_back(list2[j++]);
    }

    while (i < list1.size()) merged.push_back(list1[i++]);
    while (j < list2.size()) merged.push_back(list2[j++]);

    // Keep only top K_MAX (10) largest elements
    if (merged.size() > K_MAX)
        merged.resize(K_MAX);

    topNodes[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and topNodes
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topNodes[i] = {i};
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
            if (topNodes[root].size() < k)
                cout << "-1\n";
            else
                cout << topNodes[root][k - 1] << "\n";
        }
    }

    return 0;
}