#include <bits/stdc++.h>

using namespace std;

#define SZ(s) ((int)s.size())

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

vector<int> parent(MAXN);
vector<vector<int>> top_values(MAXN);

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

    // Always attach smaller tree to bigger one
    if (top_values[root_u].size() < top_values[root_v].size())
        swap(root_u, root_v);

    // Merge the top values
    vector<int> merged;
    int i = 0, j = 0;
    while (i < SZ(top_values[root_u]) && j < SZ(top_values[root_v])) {
        if (top_values[root_u][i] > top_values[root_v][j])
            merged.push_back(top_values[root_u][i++]);
        else
            merged.push_back(top_values[root_v][j++]);
        if (SZ(merged) == K_MAX)
            break;
    }

    while (i < SZ(top_values[root_u]) && SZ(merged) < K_MAX)
        merged.push_back(top_values[root_u][i++]);

    while (j < SZ(top_values[root_v]) && SZ(merged) < K_MAX)
        merged.push_back(top_values[root_v][j++]);

    // Update parent and top_values
    parent[root_v] = root_u;
    top_values[root_u] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_values[i] = {i};
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
            int root_v = find(v);
            if (SZ(top_values[root_v]) < k)
                cout << -1 << '\n';
            else
                cout << top_values[root_v][k - 1] << '\n';
        }
    }

    return 0;
}