#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int ll;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    vector<set<int>> sizes;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sizes.push_back({i});
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) {
                ++rank[u];
            }
            sizes[u].merge(sizes[v]);
        }
    }

    int getKthLargest(int u, int k) {
        u = find(u);
        auto& s = sizes[u];
        if (s.size() < k) {
            return -1;
        }
        auto it = s.rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << uf.getKthLargest(v, k) << endl;
        }
    }

    return 0;
}