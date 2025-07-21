#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank;
    int count;
    
    DisjointSet(int n) : parent(n), rank(n, 1), count(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
        count--;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    DisjointSet ds(H * W + 2); // +2 for virtual nodes for boundary

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                ds.unite(i * W + j, H * W); // Connect boundary cells to a virtual node
            }
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R, --C; // Convert 1-based index to 0-based index

        if (!grid[R][C]) continue;

        grid[R][C] = false;

        int id = R * W + C;
        if (R > 0 && grid[R - 1][C]) ds.unite(id, (R - 1) * W + C);
        if (R < H - 1 && grid[R + 1][C]) ds.unite(id, (R + 1) * W + C);
        if (C > 0 && grid[R][C - 1]) ds.unite(id, R * W + (C - 1));
        if (C < W - 1 && grid[R][C + 1]) ds.unite(id, R * W + (C + 1));
    }

    cout << ds.count - 1 << '\n'; // Subtract 1 because we have added a virtual node

    return 0;
}