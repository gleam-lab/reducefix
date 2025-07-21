#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    
    UnionFind(int n) : par(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        par[x] = root(par[x]);
        return par[x];
    }
    
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        size[x] += size[y];
        return true;
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    int getSize(int x) {
        return size[root(x)];
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    UnionFind uf(h * w);
    vector<map<int, int>> vertical(h), horizontal(w);
    
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-indexed
        
        if (!vertical[r].count(c)) {
            vertical[r][c] = c;
            horizontal[c][r] = r;
        } else {
            int start = vertical[r][c];
            int end = uf.root(start);
            
            // Connect the parts to the left and right of the wall before it
            int left = (start > 0) ? uf.root(start - 1) : -1;
            int right = (start < w - 1) ? uf.root(start + 1) : -1;
            
            if (left != -1) uf.unite(left, start);
            if (right != -1) uf.unite(right, start);
            
            // Remove the wall
            uf.unite(start, end);
            
            // Reassign the left and right walls
            if (left != -1) uf.unite(left, vertical[r][c]);
            if (right != -1) uf.unite(right, vertical[r][c]);
            
            // Update horizontal map
            if (horizontal[c].count(r) > 0) {
                uf.unite(horizontal[c][r], vertical[r][c]);
            }
        }
    }
    
    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int c : vertical[i]) {
            remainingWalls += uf.getSize(uf.root(c)) - 1;
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}