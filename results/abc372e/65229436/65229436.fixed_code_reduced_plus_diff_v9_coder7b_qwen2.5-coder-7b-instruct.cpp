#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
const int INF = 1e9;
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
};

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<priority_queue<Edge>> pq(n);

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.findRoot(u);
            int rv = uf.findRoot(v);
            if (ru != rv) {
                uf.unite(ru, rv);
                int rnew = uf.findRoot(ru);
                pq[rnew].push(Edge(v, 1));
                pq[rnew].push(Edge(u, 1));
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if (pq[root].size() < k) cout << "-1" << endl;
            else {
                auto it = pq[root].begin();
                advance(it, k - 1);
                cout << it->v + 1 << endl;
            }
        }
    }

    return 0;
}