#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct UF {
    vector<int> parent, rank;
    UF(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

struct Component {
    priority_queue<int> pq;
};

unordered_map<int, Component> comp;
UF uf(MAXN);

void addEdge(int u, int v) {
    int pu = uf.find(u), pv = uf.find(v);
    if (pu != pv) {
        uf.merge(pu, pv);
        comp[pu].pq.insert(v);
        comp[pv].pq.insert(u);
    } else {
        comp[pu].pq.insert(v);
        comp[pu].pq.insert(u);
    }
}

int kthLargest(int v, int k) {
    int pv = uf.find(v);
    if (comp[pv].pq.size() < k) return -1;
    auto it = comp[pv].pq.begin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) comp[i];

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) addEdge(u, v);
        else cout << kthLargest(v, k) << '\n';
    }

    return 0;
}