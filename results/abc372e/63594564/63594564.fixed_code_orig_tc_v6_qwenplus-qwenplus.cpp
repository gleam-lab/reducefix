#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) ((int)(s).size())

const int N = 2 * 100000 + 5;

vector<vector<int>> top_nodes;
vector<int> parent, size;

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

    // Ensure root_u has the larger set
    if (SZ(top_nodes[root_u]) < SZ(top_nodes[root_v])) {
        swap(root_u, root_v);
    }

    // Merge the smaller set into the larger one
    for (int x : top_nodes[root_v]) {
        top_nodes[root_u].push_back(x);
    }

    // Sort in descending order and keep top 10
    sort(top_nodes[root_u].begin(), top_nodes[root_u].end(), greater<int>());
    if (SZ(top_nodes[root_u]) > 10) {
        top_nodes[root_u].resize(10);
    }

    // Update DSU parent
    parent[root_v] = root_u;
    size[root_u] += size[root_v];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    top_nodes.resize(n + 1);
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        top_nodes[i].push_back(i);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (SZ(top_nodes[root]) >= k) {
                cout << top_nodes[root][k - 1] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}