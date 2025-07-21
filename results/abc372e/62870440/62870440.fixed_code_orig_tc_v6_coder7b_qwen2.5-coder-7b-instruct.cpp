#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

struct DSU {
    vector<int> parent, rank;
    vector<multiset<int>> sets;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        sets.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sets[i].insert(i);
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            swap(pu, pv);
        }

        parent[pu] = pv;
        rank[pv] += rank[pu];
        sets[pv].insert(sets[pu].begin(), sets[pu].end());
        sets[pu].clear();
    }

    int kthLargest(int u, int k) {
        int pu = find(u);
        auto &s = sets[pu];
        if (s.size() < k) return -1;
        auto it = s.rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            dsu.unionSets(u, v);
        } else {
            cout << dsu.kthLargest(u, k) << "\n";
        }
    }

    return 0;
}