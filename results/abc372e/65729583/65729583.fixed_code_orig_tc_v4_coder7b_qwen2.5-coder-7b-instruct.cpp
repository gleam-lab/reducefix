#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct dsu {
    vector<int> parent, rank;
    dsu(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=1;i<=n;++i) parent[i]=i;
    }
    int find(int u) {
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void unite(int u, int v) {
        u=find(u), v=find(v);
        if(rank[u]>rank[v]) parent[v]=u;
        else if(rank[u]<rank[v]) parent[u]=v;
        else {
            parent[v]=u;
            rank[u]++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    dsu uf(n);
    unordered_map<int, set<int>> g[n+1];
    
    for(int i=0;i<m;++i) {
        int t, u, v, k;
        cin >> t;
        if(t==1) {
            cin >> u >> v;
            int pu=uf.find(u), pv=uf.find(v);
            if(pu!=pv) {
                if(g[pu].size()>g[pv].size()) swap(pu,pv);
                for(int x : g[pu]) g[pv].insert(x);
                uf.unite(u,v);
            }
        } else {
            cin >> u >> k;
            int pu=uf.find(u);
            if(g[pu].size()<k) cout << -1 << "\n";
            else cout << -(*next(g[pu].begin(),k-1)) << "\n";
        }
    }
    
    return 0;
}