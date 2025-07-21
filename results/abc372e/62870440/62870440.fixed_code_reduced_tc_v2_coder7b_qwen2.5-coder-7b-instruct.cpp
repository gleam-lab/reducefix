#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 11;

struct DSU {
    vector<int> parent, rank, size;
    vector<vector<int>> pq;

    DSU(int n) : parent(n), rank(n, 1), size(n, 1), pq(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (rank[u] > rank[v]) {
            swap(u, v);
        } else if (rank[u] == rank[v]) {
            ++rank[v];
        }

        parent[u] = v;
        size[v] += size[u];

        // Merge priority queues
        auto& pq_u = pq[u], &pq_v = pq[v];
        pq_v.insert(pq_v.end(), pq_u.begin(), pq_u.end());
        sort(pq_v.begin(), pq_v.end(), greater<int>());
        while (pq_v.size() > MAXK) pq_v.pop_back();
    }

    int getKthLargest(int u, int k) {
        u = find(u);
        if (k > pq[u].size()) return -1;
        return pq[u][k - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        --u, --v; // Adjust for zero-based indexing

        if (op == 1) {
            dsu.merge(u, v);
        } else {
            cout << dsu.getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}