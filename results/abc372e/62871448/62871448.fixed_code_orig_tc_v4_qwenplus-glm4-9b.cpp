#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct UnionFind {
    vector<int> parent, size, max_val; // max_val is the maximum value in the set
    priority_queue<int, vector<int>, greater<int>> max_heap; // max heap to store the maximum values
    priority_queue<int, vector<int>, less<int>> min_heap; // min heap to store the minimum values

    UnionFind(int n) : parent(n), size(n, 1), max_val(n, -1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_sets(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        max_val[x] = max(max_val[x], max_val[y]);
        // Move max_val of the smaller tree to the root tree
        if (max_heap.size() && max_heap.top() == max_val[y]) {
            max_heap.push(max_val[x]);
        } else {
            max_heap.push(max_val[y]);
        }
        max_heap.push(max_val[x]);
        // Rebalance the heaps
        while (max_heap.size() > 2 * min_heap.size() + 1) {
            max_heap.pop();
        }
        while (!max_heap.empty() && max_heap.top() < min_heap.top()) {
            int top = min_heap.top();
            min_heap.pop();
            max_heap.pop();
            min_heap.push(top);
        }
        // Set the maximum value for the new root
        max_val[x] = max_heap.top();
    }

    // Other member functions for union and find operations
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    // Process queries
    // ...
    return 0;
}