#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+5;

class UF {
public:
    vector<int> parent, size, rank, index;
    unordered_map<int, priority_queue<int>> pq;

    UF(int n) {
        parent.resize(n+1); iota(parent.begin(), parent.end(), 0);
        size.resize(n+1, 1);
        rank.resize(n+1, 1);
        index.resize(n+1);
    }

    int find(int u) {
        if(u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        rank[u] = max(rank[u], rank[v]+1);
        pq[u].merge(pq[v]);
        pq[u].push(-v);
    }

    int getKth(int u, int k) {
        u = find(u);
        if(k > pq[u].size()) return -1;
        auto it = pq[u].begin();
        advance(it, k-1);
        return -(*it);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UF uf(n);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << uf.getKth(v, k) << '\n';
        }
    }

    return 0;
}