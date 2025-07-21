#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct DSU {
    vector<int> parent, rank;
    vector<set<int>> sets;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sets.push_back({i});
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] > rank[py]) {
            swap(px, py);
        }

        parent[px] = py;
        rank[py] += rank[px];

        // Merge sets
        auto &s1 = sets[px], &s2 = sets[py];
        s2.insert(s1.begin(), s1.end());
        s1.clear();
        sets.erase(sets.begin() + px);
    }

    const set<int>& getSet(int x) {
        return sets[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            dsu.unite(u, v);
        } else {
            int root = dsu.find(v);
            const auto& s = dsu.getSet(root);
            if (v > n || s.size() < u) {
                cout << "-1\n";
            } else {
                auto it = prev(s.upper_bound(v));
                cout << *it << "\n";
            }
        }
    }

    return 0;
}