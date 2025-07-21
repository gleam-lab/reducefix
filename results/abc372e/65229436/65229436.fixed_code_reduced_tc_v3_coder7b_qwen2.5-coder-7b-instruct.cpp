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
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(uf.findRoot(u)!=uf.findRoot(v)) {
                uf.unite(u, v);
                adj[u].push_back(v);
                adj[v].push_back(u);
                degree[u]++;
                degree[v]++;
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            if(degree[v]<k-1) cout << "-1" << endl;
            else {
                priority_queue<int, vector<int>, greater<int>> pq;
                for(int child : adj[v]) {
                    if(degree[child]>degree[v]-1) pq.push(child);
                    if(pq.size()>k-1) pq.pop();
                }
                cout << pq.top() + 1 << endl;
            }
        }
    }

    return 0;
}