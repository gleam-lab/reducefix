#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
vector<int> parent(MAXN);

// Initialize the union-find data structure
void init(int n) {
    iota(parent.begin(), parent.begin() + n, 0);
}

// Find the root of the set containing x
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

// Merge sets containing x and y
void merge(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    init(h * w);
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        int id = r * w + c;
        
        // Check if there is already a wall at (r, c)
        if (find(id) != id) {
            continue;
        }
        
        // Try to destroy walls in all four directions
        if (r > 0 && find(id - w) == id - w) {
            merge(id, id - w);
        }
        if (r < h - 1 && find(id + w) == id + w) {
            merge(id, id + w);
        }
        if (c > 0 && find(id - 1) == id - 1) {
            merge(id, id - 1);
        }
        if (c < w - 1 && find(id + 1) == id + 1) {
            merge(id, id + 1);
        }
    }
    
    unordered_set<int> unique_roots;
    for (int i = 0; i < h * w; ++i) {
        unique_roots.insert(find(i));
    }
    
    cout << h * w - unique_roots.size() << endl;
    
    return 0;
}