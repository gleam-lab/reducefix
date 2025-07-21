#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> uni;
  
    Union_Find(int n) {
        sz.resize(n + 1, 1);
        par.resize(n + 1, -1);
        uni.resize(n + 1);
    }
  
    int root(int v) {
        if (par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }
  
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
  
    void merge(int x, int y) {
        if (!issame(x, y)) {
            x = root(x), y = root(y);
            if (y > x) swap(x, y);
            sz[x] += sz[y];
            par[y] = x;
            uni[x].insert(uni[x].end(), uni[y].begin(), uni[y].end());
        }
    }
  
    void add_edge(int x, int y) {
        merge(x, y);
    }
  
    vector<int> get_neighbors(int v) {
        int r = root(v);
        return uni[r];
    }
  
    int get_kth_largest(int v, int k) {
        int r = root(v);
        if (k > sz[r]) return -1; // Not enough vertices connected to v
        if (k <= uni[r].size()) return uni[r][uni[r].size() - k]; // k-th largest
        return -1;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
  
    while (q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        if (ty == 1) {
            uf.add_edge(a, b);
        } else {
            int k = b;
            vector<int> neighbors = uf.get_neighbors(a);
            if (k > neighbors.size()) {
                cout << -1 << endl;
            } else {
                cout << neighbors[neighbors.size() - k] << endl;
            }
        }
    }
}