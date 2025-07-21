#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> rank;
    vector<vector<P>> component;  // Store tuples of (vertex, rank) for top 10 vertices

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        component.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            component[i].emplace_back(i, 0);
        }
    }

    int root(int v) {
        if (parent[v] == v) return v;
        else {
            parent[v] = root(parent[v]);
            return parent[v];
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (rank[x] < rank[y]) swap(x, y);
        if (x == y) return;
        if (rank[x] == rank[y]) rank[x]++;

        if (component[x].size() > 10) component[x].pop_back();  // Keep only top 10
        if (component[y].size() > 10) component[y].pop_back();

        component[x].insert(all(component[y]));
        component[y].clear();

        sort(all(component[x]), [](const P& a, const P& b) { return a.second > b.second; });
        
        for (int i = 0; i < component[x].size(); i++) {
            component[x][i].first = component[x][i].first + component[x][i].second;
        }
    }

    void add_edge(int u, int v) {
        merge(u, v);
    }

    int query(int v, int k) {
        v = root(v);
        if (component[v].size() <= k) return -1;
        return component[v][k - 1].first;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> results;

    for (int i = 0; i < q; i++) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.add_edge(u, v);
        } else {
            cin >> k;
            results.push_back(uf.query(u, k));
        }
    }

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}