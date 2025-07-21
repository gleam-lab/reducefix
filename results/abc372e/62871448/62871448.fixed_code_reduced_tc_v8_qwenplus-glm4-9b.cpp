#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<int> rank(MAXN);
vector<vector<int>> graph(MAXN);

int find(int x) {
  if (parent[x] == x) return x;
  parent[x] = find(parent[x]); // Path compression
  return parent[x];
}

void unionSets(int x, int y) {
  int rootX = find(x);
  int rootY = find(y);

  if (rootX != rootY) {
    // Union by rank
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
      graph[rootX].insert(graph[rootX].end(), graph[rootY].begin(), graph[rootY].end());
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
      graph[rootY].insert(graph[rootY].end(), graph[rootX].begin(), graph[rootX].end());
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
      graph[rootX].insert(graph[rootX].end(), graph[rootY].begin(), graph[rootY].end());
    }
  }
}

int kthLargest(int v, int k) {
  v = find(v);
  vector<int> vertices = graph[v];
  sort(vertices.rbegin(), vertices.rend()); // Sort in descending order
  return vertices[k - 1]; // k-th largest vertex is at k-1 index due to reverse sort
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    rank[i] = 0;
  }

  int u, v, k;
  for (int i = 0; i < q; ++i) {
    cin >> u >> v;
    if (u == 1) {
      cin >> v;
      unionSets(u, v);
    } else if (u == 2) {
      cin >> v >> k;
      cout << kthLargest(v, k) << endl;
    }
  }

  return 0;
}