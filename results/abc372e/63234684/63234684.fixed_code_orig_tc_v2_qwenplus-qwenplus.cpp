#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using vi = vector<int>;
using vvi = vector<vi>;

struct UnionFind {
    vi parent, sz;
    vvi members;
    vector<vi> top_k;

    UnionFind(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        members.resize(n);
        top_k.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            members[i].push_back(i);
            top_k[i].push_back(i);
        }
    }

    int find(int x) {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        // Always merge smaller into larger
        if (sz[x] < sz[y]) swap(x, y);

        // Merge members
        for (int v : members[y]) {
            members[x].push_back(v);
        }

        // Recompute top_k[x] (keep top 10 max elements)
        sort(members[x].rbegin(), members[x].rend());
        top_k[x] = vi(members[x].begin(), min(members[x].begin() + 10, members[x].end()));

        // Clear y to save space
        members[y].clear();
        top_k[y].clear();

        sz[x] += sz[y];
        parent[y] = x;

        return true;
    }

    int query(int v, int k) {
        int root = find(v);
        if ((int)top_k[root].size() < k) return -1;
        return top_k[root][k - 1] + 1; // convert to 1-based
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uf.unite(a - 1, b - 1);
        } else {
            cout << uf.query(a - 1, b) << '\n';
        }
    }

    return 0;
}