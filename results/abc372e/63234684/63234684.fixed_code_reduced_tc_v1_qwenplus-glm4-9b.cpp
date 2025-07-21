#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> par, rank, size;
    
    UnionFind(int n) {
        par.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; ++i) par[i] = i;
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            if (rank[x] == rank[y]) rank[x]++;
            par[y] = x;
            size[x] += size[y];
        }
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> answers;
    
    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.unite(u, v);
        } else {
            answers.push_back(uf.getSize(v));
        }
    }
    
    for (int ans : answers) {
        cout << ans << endl;
    }
    
    return 0;
}