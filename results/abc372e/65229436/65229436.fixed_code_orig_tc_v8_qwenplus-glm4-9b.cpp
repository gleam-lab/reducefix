#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF=1e9;
struct UnionFind {
    vector<int> parent, rank, size;
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
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
        if (size[rx] < size[ry]) swap(rx, ry);
        parent[rx] = ry;
        size[ry] += size[rx];
        return true;
    }
    int getSize(int x) {
        return size[findRoot(x)];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> component(n);
    rep(i, n) component[i].push_back(i);
    for(int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if(com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
            int root_u = uf.findRoot(u);
            int root_v = uf.findRoot(v);
            if(root_u != root_v) {
                vector<int>& smaller_component = component[root_u].size() < component[root_v].size() ? component[root_u] : component[root_v];
                vector<int>& larger_component = component[root_u].size() < component[root_v].size() ? component[root_v] : component[root_u];
                smaller_component.insert(smaller_component.end(), larger_component.begin(), larger_component.end());
                larger_component.clear();
            }
        } else if(com == 2) {
            int v, k;
            cin >> v >> k;
            int root_v = uf.findRoot(v);
            if(k > component[root_v].size()) cout << -1 << endl;
            else cout << component[root_v][component[root_v].size() - k] + 1 << endl;
        }
    }
    return 0;
}