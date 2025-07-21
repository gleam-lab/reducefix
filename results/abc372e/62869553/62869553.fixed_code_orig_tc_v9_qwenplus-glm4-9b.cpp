#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int findSet(int x) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = findSet(x);
        int rootY = findSet(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n + 1);
    
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        
        if (op == 1) {
            uf.unionSets(u, v);
        } else {
            int root = uf.findSet(v);
            vector<int> connected;
            for (int i = 1; i <= n; ++i) {
                if (uf.findSet(i) == root) {
                    connected.push_back(i);
                }
            }
            sort(connected.rbegin(), connected.rend()); // Sort in descending order
            
            if (k > connected.size()) {
                cout << -1 << endl;
            } else {
                cout << connected[k - 1] << endl;
            }
        }
    }
    
    return 0;
}