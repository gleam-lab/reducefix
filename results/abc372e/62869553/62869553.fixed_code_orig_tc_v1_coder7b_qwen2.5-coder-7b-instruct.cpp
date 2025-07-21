#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

class UF {
    vector<int> parent, size;
public:
    UF(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
            pq[v].merge(pq[u]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UF uf(n);
    for (int i = 1; i <= n; ++i) pq[i].push(i);

    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;

        if (op == 1) {
            uf.unite(ix, iy);
        } else {
            int root = uf.find(ix);
            if (pq[root].size() < iy) cout << "-1\n";
            else {
                auto it = pq[root].begin();
                advance(it, iy - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}