#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) swap(pu, pv);
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n + 1);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            int pu = uf.find(u), pv = uf.find(v);
            if (pu != pv) {
                uf.merge(u, v);
                pq[pu].push(v);
                pq[pv].push(u);
            }
        } else {
            int pu = uf.find(u);
            if (pq[pu].size() >= v) {
                auto it = pq[pu].nth_element(v - 1);
                cout << *it << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}