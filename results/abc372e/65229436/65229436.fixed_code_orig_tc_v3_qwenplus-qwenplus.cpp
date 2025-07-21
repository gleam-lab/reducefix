#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
typedef long long ll;
using pii = pair<int, int>;

const int MAX_K = 10;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> top_nodes;

    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        top_nodes.resize(n);
        for (int i = 0; i < n; ++i)
            top_nodes[i].push_back(i);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;

        // Always merge smaller into larger
        if (top_nodes[rx].size() < top_nodes[ry].size())
            swap(rx, ry);

        // Merge ry's top nodes into rx's
        top_nodes[rx].insert(top_nodes[rx].end(), all(top_nodes[ry]));
        sort(rall(top_nodes[rx])); // Sort descending

        // Keep only the first MAX_K elements
        if (top_nodes[rx].size() > MAX_K)
            top_nodes[rx].resize(MAX_K);

        parent[ry] = rx;
        top_nodes[ry].clear();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<int> ans;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (t == 2) {
            int v, k;
            cin >> v >> k;
            v--;

            auto& nodes = uf.top_nodes[uf.find(v)];
            if ((int)nodes.size() < k)
                ans.push_back(-1);
            else
                ans.push_back(nodes[k - 1] + 1); // Convert back to 1-based index
        }
    }

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}