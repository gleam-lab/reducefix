#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXQ = 2e5 + 10;
const int INF = 1e9;

struct DSU {
    vector<int> parent, rank, size;
    DSU(int n) : parent(n), rank(n, 1), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        rank[y] += rank[x];
        size[y] += size[x];
    }
};

struct PriorityQueue {
    multiset<int> pq;
    void insert(int val) {
        pq.insert(val);
    }
    void remove(int val) {
        auto it = pq.find(val);
        if (it != pq.end()) pq.erase(it);
    }
    int getKthLargest(int k) {
        auto it = pq.rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    DSU dsu(n + 1);
    vector<PriorityQueue> pq(n + 1);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            int pu = dsu.find(u), pv = dsu.find(v);
            if (pu != pv) {
                dsu.unite(pu, pv);
                pq[pu].remove(u);
                pq[pv].remove(v);
                pq[pu].insert(v);
                pq[pv].insert(u);
            }
        } else {
            cin >> v >> k;
            int root = dsu.find(v);
            if (pq[root].size() < k) cout << "-1\n";
            else cout << pq[root].getKthLargest(k) << "\n";
        }
    }

    return 0;
}