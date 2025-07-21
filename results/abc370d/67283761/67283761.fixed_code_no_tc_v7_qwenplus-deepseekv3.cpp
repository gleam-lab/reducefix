#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int size) : parent(size) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) parent[u] = v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> walls(H, vector<bool>(W, true));
    int remaining = H * W;
    
    DSU left(H * W);
    DSU right(H * W);
    DSU up(H * W);
    DSU down(H * W);
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        
        if (walls[r][c]) {
            walls[r][c] = false;
            --remaining;
        } else {
            // Check left
            int pos = r * W + c;
            int next_pos = pos - 1;
            if (c > 0) {
                int root = left.find(next_pos);
                int nr = root / W;
                int nc = root % W;
                if (walls[nr][nc]) {
                    walls[nr][nc] = false;
                    --remaining;
                    left.unite(next_pos, next_pos - 1);
                }
            }
            
            // Check right
            next_pos = pos + 1;
            if (c < W - 1) {
                int root = right.find(next_pos);
                int nr = root / W;
                int nc = root % W;
                if (walls[nr][nc]) {
                    walls[nr][nc] = false;
                    --remaining;
                    right.unite(next_pos, next_pos + 1);
                }
            }
            
            // Check up
            next_pos = pos - W;
            if (r > 0) {
                int root = up.find(next_pos);
                int nr = root / W;
                int nc = root % W;
                if (walls[nr][nc]) {
                    walls[nr][nc] = false;
                    --remaining;
                    up.unite(next_pos, next_pos - W);
                }
            }
            
            // Check down
            next_pos = pos + W;
            if (r < H - 1) {
                int root = down.find(next_pos);
                int nr = root / W;
                int nc = root % W;
                if (walls[nr][nc]) {
                    walls[nr][nc] = false;
                    --remaining;
                    down.unite(next_pos, next_pos + W);
                }
            }
        }
    }
    
    cout << remaining << '\n';
    
    return 0;
}