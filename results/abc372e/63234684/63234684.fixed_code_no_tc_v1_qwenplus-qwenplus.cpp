#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int KEEP_TOP = 10;

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> top_nodes;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        top_nodes.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            top_nodes[i].push_back(i);
        }
    }

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

        // Always merge smaller to bigger
        if (size[root_u] < size[root_v])
            swap(root_u, root_v);

        // Merge the smaller component into the larger one
        size[root_u] += size[root_v];
        parent[root_v] = root_u;

        // Merge the top nodes list and keep only top KEEP_TOP elements
        for (int node : top_nodes[root_v]) {
            top_nodes[root_u].push_back(node);
        }

        // Sort in descending order and keep top 10
        sort(top_nodes[root_u].rbegin(), top_nodes[root_u].rend());
        if (top_nodes[root_u].size() > KEEP_TOP) {
            top_nodes[root_u].resize(KEEP_TOP);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;

        if (type == 1) {
            uf.unite(a, b);
        } else {
            int root = uf.find(a);
            if (b >= (int)uf.top_nodes[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << uf.top_nodes[root][b] + 1 << '\n'; // Convert back to 1-based index
            }
        }
    }

    return 0;
}