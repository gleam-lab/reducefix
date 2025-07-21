#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class UnionFind {
private:
  vector<int> parent;
  vector<int> rank;
  vector<priority_queue<int, vector<int>, greater<int>>> maxHeap;

public:
  UnionFind(int size) : parent(size), rank(size, 0), maxHeap(size) {
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
      maxHeap[i].push(i);
    }
  }

  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
        maxHeap[rootY].splice(maxHeap[rootY].end(), maxHeap[rootX]);
      } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
        maxHeap[rootX].splice(maxHeap[rootX].end(), maxHeap[rootY]);
      } else {
        parent[rootY] = rootX;
        maxHeap[rootX].splice(maxHeap[rootX].end(), maxHeap[rootY]);
        rank[rootX] += 1;
      }
    }
  }

  int kthLargest(int x, int k) {
    int root = find(x);
    if (maxHeap[root].size() < k) {
      return -1; // If there are not enough vertices, return -1
    }
    priority_queue<int, vector<int>, greater<int>> tempHeap;
    for (int i = 0; i < k; ++i) {
      tempHeap.push(maxHeap[root].top());
      maxHeap[root].pop();
    }
    int kthLargest = tempHeap.top();
    while (!tempHeap.empty()) {
      maxHeap[root].push(tempHeap.top());
      tempHeap.pop();
    }
    return kthLargest;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);

  while (q--) {
    int type, u, v;
    cin >> type >> u >> v;
    if (type == 1) {
      uf.unite(u - 1, v - 1);
    } else {
      int k;
      cin >> k;
      cout << uf.kthLargest(u - 1, k) << endl;
    }
  }

  return 0;
}