#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(!degree[u] && !degree[v]) {
                uf.unite(u, v);
                adj[u].push_back(v);
                adj[v].push_back(u);
                degree[u]++;
                degree[v]++;
            } else if(degree[u] && !degree[v]) {
                int pu = uf.findRoot(u);
                if(pu!=v) {
                    uf.unite(pu, v);
                    adj[pu].push_back(v);
                    adj[v].push_back(pu);
                    degree[v]++;
                }
            } else if(!degree[u] && degree[v]) {
                int pv = uf.findRoot(v);
                if(pv!=u) {
                    uf.unite(pv, u);
                    adj[pv].push_back(u);
                    adj[u].push_back(pv);
                    degree[u]++;
                }
            } else {
                int pu = uf.findRoot(u), pv = uf.findRoot(v);
                if(pu!=pv) {
                    if(adj[pu].size()<adj[pv].size()) swap(pu, pv);
                    uf.unite(pu, pv);
                    int pr = uf.findRoot(pu);
                    for (int x:adj[pv]) adj[pr].push_back(x);
                    adj[pv].clear();
                }
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            int rv = uf.findRoot(v);
            if(adj[rv].size()<k) ans.push_back(-1);
            else {
                sort(all(adj[rv]));
                reverse(all(adj[rv]));
                ans.push_back(adj[rv][k-1]+1);
            }
        }
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}