#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> top_nodes;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        top_nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            top_nodes[i].push_back(i);
        }
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        // Always merge smaller into larger for efficiency
        if (size[root_x] < size[root_y]) swap(root_x, root_y);

        // Merge the top nodes list
        for (int val : top_nodes[root_y]) {
            top_nodes[root_x].push_back(val);
        }

        // Sort and keep at most top 10 largest
        sort(top_nodes[root_x].rbegin(), top_nodes[root_x].rend());
        if (top_nodes[root_x].size() > 10) {
            top_nodes[root_x].resize(10);
        }

        // Update size
        size[root_x] += size[root_y];
        parent[root_y] = root_x;
    }

    vector<int>& get_top(int x) {
        return top_nodes[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            auto& top = uf.get_top(v);
            if (k > (int)top.size()) {
                cout << -1 << '\n';
            } else {
                cout << top[k - 1] + 1 << '\n'; // Convert from 0-indexed to 1-based
            }
        }
    }

    return 0;
}