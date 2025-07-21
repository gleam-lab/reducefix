#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    const int MAX = h * w + 5;
    vector<UnionFind> ufs_row(h, UnionFind(w)), ufs_col(w, UnionFind(h));
    
    auto get_next_left = [&](int r, int c) -> int {
        if (c == 0)
            return -1;
        int res = ufs_row[r].find(c - 1);
        while (res > 0 && ufs_row[r].find(res - 1) == ufs_row[r].find(res))
            res--;
        return res;
    };
    
    auto get_next_right = [&](int r, int c) -> int {
        if (c == w - 1)
            return -1;
        int res = ufs_row[r].find(c + 1);
        while (res < w - 1 && ufs_row[r].find(res + 1) == ufs_row[r].find(res))
            res++;
        return res;
    };
    
    auto get_next_up = [&](int r, int c) -> int {
        if (r == 0)
            return -1;
        int res = ufs_col[c].find(r - 1);
        while (res > 0 && ufs_col[c].find(res - 1) == ufs_col[c].find(res))
            res--;
        return res;
    };
    
    auto get_next_down = [&](int r, int c) -> int {
        if (r == h - 1)
            return -1;
        int res = ufs_col[c].find(r + 1);
        while (res < h - 1 && ufs_col[c].find(res + 1) == ufs_col[c].find(res))
            res++;
        return res;
    };
    
    // 0: empty, 1: wall
    vector<vector<bool>> has_wall(h, vector<bool>(w, true));
    
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (!has_wall[r][c]) {
            // Bomb explodes in four directions
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            // Up
            int nr = get_next_up(r, c);
            if (nr != -1) {
                has_wall[nr][c] = false;
                ufs_col[c].unite(nr, r);
            }
            
            // Down
            nr = get_next_down(r, c);
            if (nr != -1) {
                has_wall[nr][c] = false;
                ufs_col[c].unite(nr, r);
            }
            
            // Left
            int nc = get_next_left(r, c);
            if (nc != -1) {
                has_wall[r][nc] = false;
                ufs_row[r].unite(nc, c);
            }
            
            // Right
            nc = get_next_right(r, c);
            if (nc != -1) {
                has_wall[r][nc] = false;
                ufs_row[r].unite(nc, c);
            }
        } else {
            // Bomb destroys the wall at this position
            has_wall[r][c] = false;
        }
    }
    
    // Count remaining walls
    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            count += has_wall[i][j];
        }
    }
    
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}