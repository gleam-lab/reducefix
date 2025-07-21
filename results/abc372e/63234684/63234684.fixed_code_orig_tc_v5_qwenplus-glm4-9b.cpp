#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
  vector<int> sz, par, rank;
  vector<vector<int>> adj;

  Union_Find(int n) {
    par.resize(n, -1);
    sz.resize(n, 1);
    rank.resize(n, 0);
    adj.resize(n);
  }

  int root(int v) {
    if (par[v] == -1) return v;
    return par[v] = root(par[v]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (rank[x] < rank[y]) swap(x, y);
    if (x == y) return;
    par[x] = y;
    sz[y] += sz[x];
    if (rank[x] == rank[y]) rank[y]++;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  Union_Find uf(n);

  rep(i, q) {
    int ty, u, v;
    cin >> ty >> u >> v;
    if (ty == 1) {
      uf.merge(u, v);
    } else {
      if (!uf.issame(u, v)) {
        cout << -1 << endl;
      } else {
        vector<int> connected = uf.adj[uf.root(u)];
        if (connected.size() <= v) {
          cout << -1 << endl;
        } else {
          cout << connected[v] << endl;
        }
      }
    }
  }

  return 0;
}