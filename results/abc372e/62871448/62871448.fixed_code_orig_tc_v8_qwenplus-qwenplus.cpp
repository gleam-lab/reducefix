#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_k[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Always merge smaller into larger
    if ((int)top_k[root_u].size() < (int)top_k[root_v].size())
        swap(root_u, root_v);

    // Merge top_k from root_v into root_u
    vector<int> merged;
    int i = 0, j = 0;
    while (i < (int)top_k[root_u].size() && j < (int)top_k[root_v].size() && merged.size() < K_MAX) {
        if (top_k[root_u][i] > top_k[root_v][j]) {
            merged.push_back(top_k[root_u][i]);
            i++;
        } else {
            merged.push_back(top_k[root_v][j]);
            j++;
        }
    }

    while (i < (int)top_k[root_u].size() && merged.size() < K_MAX) {
        merged.push_back(top_k[root_u][i]);
        i++;
    }

    while (j < (int)top_k[root_v].size() && merged.size() < K_MAX) {
        merged.push_back(top_k[root_v][j]);
        j++;
    }

    top_k[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
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
            if ((int)top_k[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_k[root][k - 1] << '\n';
        }
    }

    return 0;
}