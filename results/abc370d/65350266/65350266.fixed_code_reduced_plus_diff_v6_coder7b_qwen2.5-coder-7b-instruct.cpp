#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int _n): n(_n), tree(4 * _n) {}
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) update(idx * 2, l, mid, pos, val);
            else update(idx * 2 + 1, mid + 1, r, pos, val);
            tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }
    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return min(query(idx * 2, l, mid, ql, qr), query(idx * 2 + 1, mid + 1, r, ql, qr));
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    SegmentTree col[h][w];
    SegmentTree row[w][h];

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            col[i][j] = SegmentTree(w);
            row[j][i] = SegmentTree(h);
        }
    }

    for(int qi = 0; qi < q; ++qi){
        int r, c;
        cin >> r >> c;
        --r, --c;
        if(grid[r][c]){
            grid[r][c] = 0;
            for(int j = 0; j < w; ++j){
                col[r][j].update(j, 0, w-1, c, 1);
            }
            for(int i = 0; i < h; ++i){
                row[i][c].update(i, 0, h-1, r, 1);
            }
        }else{
            int left = col[r][c].query(0, 0, w-1, 0, c-1);
            int right = col[r][c].query(0, 0, w-1, c+1, w-1);
            int up = row[c][r].query(0, 0, h-1, 0, r-1);
            int down = row[c][r].query(0, 0, h-1, r+1, h-1);
            grid[r][c] = 1;
            for(int j = 0; j < w; ++j){
                if(j >= left && j <= c){
                    col[r][j].update(j, 0, w-1, c, 0);
                }
                if(j <= right && j >= c){
                    col[r][j].update(j, 0, w-1, c, 0);
                }
            }
            for(int i = 0; i < h; ++i){
                if(i >= up && i <= r){
                    row[i][c].update(i, 0, h-1, r, 0);
                }
                if(i <= down && i >= r){
                    row[i][c].update(i, 0, h-1, r, 0);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(grid[i][j]) ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}