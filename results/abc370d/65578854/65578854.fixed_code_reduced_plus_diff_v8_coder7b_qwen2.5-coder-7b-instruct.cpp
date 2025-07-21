#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) : n(size), tree(4 * size) {}

    void update(int idx, int val, int node, int tl, int tr) {
        if (tl == tr) {
            tree[node] += val;
        } else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                update(idx, val, 2 * node, tl, tm);
            } else {
                update(idx, val, 2 * node + 1, tm + 1, tr);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int l, int r, int node, int tl, int tr) {
        if (l > r) {
            return INT_MAX;
        }
        if (l == tl && r == tr) {
            return tree[node];
        }
        int tm = (tl + tr) / 2;
        return min(query(l, min(r, tm), 2 * node, tl, tm), 
                   query(max(l, tm + 1), r, 2 * node + 1, tm + 1, tr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    SegmentTree row(H), col(W);

    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;  // Convert to 0-based index

        if(grid[r][c]) {
            grid[r][c] = false;
            row.update(r, 1, 1, 0, H-1);
            col.update(c, 1, 1, 0, W-1);
        } else {
            int rm = row.query(r+1, H-1, 1, 0, H-1);
            int lm = row.query(0, r-1, 1, 0, H-1);
            int cm = col.query(c+1, W-1, 1, 0, W-1);
            int lm2 = col.query(0, c-1, 1, 0, W-1);
            
            int dist = min({rm, lm, cm, lm2});
            if(dist == INT_MAX) {
                grid[r][c] = true;
                row.update(r, -1, 1, 0, H-1);
                col.update(c, -1, 1, 0, W-1);
            } else {
                r -= dist;
                c -= dist;
                grid[r][c] = false;
                row.update(r, 1, 1, 0, H-1);
                col.update(c, 1, 1, 0, W-1);
            }
        }
    }

    int count = 0;
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            count += grid[i][j];
        }
    }
    cout << count << "\n";

    return 0;
}