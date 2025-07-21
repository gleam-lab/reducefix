#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(all(parent), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<set<int>> component(N);
    vector<set<int>*> compPtr(N);
    for (int i = 0; i < N; ++i) {
        component[i].insert(i);
        compPtr[i] = &component[i];
    }

    vector<int> ans;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.find(u), rv = uf.find(v);
            if (ru != rv) {
                // Always merge smaller set into larger
                if (compPtr[ru]->size() < compPtr[rv]->size()) {
                    swap(ru, rv);
                }
                for (int x : *compPtr[rv]) {
                    compPtr[ru]->insert(x);
                }
                uf.unite(ru, rv);
                int root = uf.find(ru);
                compPtr[root] = compPtr[ru];
                compPtr[rv] = compPtr[root]; // point to new root set
                compPtr[ru] = compPtr[root]; // ensure both roots point to same set
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.find(v);
            auto& s = *compPtr[root];
            if (s.size() < k) {
                ans.push_back(-1);
            } else {
                auto it = s.rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (auto x : ans) cout << x << '\n';
}