#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct UnionFind {
  vector<int> sz, par;
  vector<vector<int>> adj;

  UnionFind(int n) {
    sz.resize(n, 1);
    par.resize(n, -1);
    adj.resize(n);
  }

  int root(int v) {
    if (par[v] == -1) return v;
    else return par[v] = root(par[v]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  void merge(int x, int y) {
    x = root(x), y = root(y);
    if (y > x) swap(x, y); // Ensure x is always smaller
    if (x == y) return;
    sz[x] += sz[y];
    sz[y] = 0;
    par[y] = x;
    adj[x].insert(adj[x].end(), adj[y].begin(), adj[y].end());
    adj[y].clear();
    sort(adj[x].begin(), adj[x].end());
    adj[x].resize(min((int)adj[x].size(), 10));
  }

  int kthLargest(int v, int k) {
    v = root(v);
    if (k > adj[v].size()) return -1;
    return adj[v][k - 1];
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);

  rep(i, q) {
    int ty, a, b;
    cin >> ty >> a >> b;
    a--, b--; // Adjusting indices for 0-based indexing
    if (ty == 1) {
      uf.merge(a, b);
    } else {
      int result = uf.kthLargest(b, a); // k is now the first parameter
      cout << result << endl;
    }
  }

  return 0;
}