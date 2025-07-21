#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define par(x) find(x), size[find(x)]

struct UnionFind {
  vector<int> parent, size, rank;

  UnionFind(int n) {
    parent.resize(n);
    size.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y);
    if (rank[x] == rank[y]) rank[x]++;
    parent[y] = x;
    size[x] += size[y];
    return true;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  vector<int> componentSize(n, 1), vertexComponent(n);
  multiset<int> verticesInComponents[n];

  rep(i, q) {
    int queryType, u, v;
    cin >> queryType >> u >> v;
    u--; v--;

    if (queryType == 1) {
      if (uf.unionSets(u, v)) {
        int rootU = uf.find(u);
        int rootV = uf.find(v);
        verticesInComponents[rootU].insert(v);
        verticesInComponents[rootV].insert(u);
      }
    } else if (queryType == 2) {
      int vRoot = uf.find(v);
      if (componentSize[vRoot] < v) {
        cout << -1 << endl;
      } else {
        cout << *(verticesInComponents[vRoot].lower_bound(v)) << endl;
      }
    }
    componentSize[uf.find(u)] = uf.size[u];
    componentSize[uf.find(v)] = uf.size[v];
  }

  return 0;
}