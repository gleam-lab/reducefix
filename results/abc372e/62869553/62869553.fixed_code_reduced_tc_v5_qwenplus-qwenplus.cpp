#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_vals[MAXN]; // Stores up to 10 largest values per component

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by size or rank
void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
        return;

    // Always merge smaller into larger to optimize
    if (top_vals[root_x].size() < top_vals[root_y].size())
        swap(root_x, root_y);

    // Merge the values
    for (int val : top_vals[root_y]) {
        top_vals[root_x].push_back(val);
    }

    // Sort descending and keep top K_MAX values
    sort(top_vals[root_x].begin(), top_vals[root_x].end(), greater<int>());
    if (top_vals[root_x].size() > K_MAX)
        top_vals[root_x].resize(K_MAX);

    parent[root_y] = root_x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top_vals
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vals[i] = {i};
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
            if (k > (int)top_vals[root_v].size()) {
                cout << "-1\n";
            } else {
                cout << top_vals[root_v][k - 1] << "\n";
            }
        }
    }

    return 0;
}