#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define rrep(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for(int i = (int)(n) - 1; i >= 1; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

vb grid;
vector<vi> row;
vector<vi> col;

void removeWall(int x, int y) {
    grid[x][y] = false;
    row[x].erase(y);
    col[y].erase(x);
}

void bin(int r, int c) {
    removeWall(r, c);
    for (int i = r - 1; i >= 0 && row[r][i]; --i) {
        removeWall(i, c);
    }
    for (int i = r + 1; i < grid.size() && row[r][i]; ++i) {
        removeWall(i, c);
    }
    for (int j = c - 1; j >= 0 && col[c][j]; --j) {
        removeWall(r, j);
    }
    for (int j = c + 1; j < grid[0].size() && col[c][j]; ++j) {
        removeWall(r, j);
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    grid.resize(h + 2, vb(w + 2, true));
    row.resize(h + 2, vi());
    col.resize(w + 2, vi());

    rep(i, h + 2) {
        rep(j, w + 2) {
            if (i > 0 && j > 0) {
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }

    rep(i, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (grid[r + 1][c + 1]) {
            bin(r + 1, c + 1);
        }
    }

    int remainingWalls = 0;
    rep(i, h + 1) {
        rep(j, w + 1) {
            remainingWalls += grid[i][j];
        }
    }
    cout << remainingWalls << endl;

    return 0;
}