#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

struct DSU {
    vector<int> parent, rank, size;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[MAXN];

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void unionSets(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (rank[u] > rank[v]) {
                parent[v] = u;
                pq[u].merge(pq[v]);
                size[u] += size[v];
            } else if (rank[u] < rank[v]) {
                parent[u] = v;
                pq[v].merge(pq[u]);
                size[v] += size[u];
            } else {
                parent[v] = u;
                pq[u].merge(pq[v]);
                size[u] += size[v];
                rank[u]++;
            }
        }
    }

    void insertEdge(int u, int v, int weight) {
        u = find(u), v = find(v);
        pq[u].push({weight, v});
        pq[v].push({weight, u});
    }

    int getKthLargest(int u, int k) {
        u = find(u);
        auto& pq_u = pq[u];
        if (pq_u.size() < k) return -1;
        nth_element(begin(pq_u), begin(pq_u) + k - 1, end(pq_u));
        return pq_u[k - 1].first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            dsu.insertEdge(u, v, 1); // Using dummy weight 1 for simplicity
        } else {
            cin >> u >> k;
            cout << dsu.getKthLargest(u, k) << '\n';
        }
    }

    return 0;
}