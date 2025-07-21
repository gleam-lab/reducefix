#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
vector<vector<int>> grid(MAXN, vector<int>(MAXN, 1));
set<pair<int, int>> rows[MAXN], cols[MAXN];

void update(int x, int y, int dx, int dy) {
    int nx = x + dx, ny = y + dy;
    while(nx > 0 && nx <= MAXN && ny > 0 && ny <= MAXN && !grid[nx][ny]) {
        rows[x].insert({nx, ny});
        cols[y].insert({nx, ny});
        nx += dx;
        ny += dy;
    }
}

void detonate(int x, int y) {
    if(grid[x][y]) {
        grid[x][y] = 0;
        update(x, y, -1, 0);
        update(x, y, 1, 0);
        update(x, y, 0, -1);
        update(x, y, 0, 1);
    } else {
        auto rx = rows[x].lower_bound({x, y});
        if(rx != rows[x].begin()) {
            --rx;
            int nx = (*rx).first, ny = (*rx).second;
            grid[nx][ny] = 0;
            rows[nx].erase({nx, ny});
            cols[ny].erase({nx, ny});
            update(nx, ny, -1, 0);
            update(nx, ny, 1, 0);
            update(nx, ny, 0, -1);
            update(nx, ny, 0, 1);
        }
        rx = rows[x].upper_bound({x, y});
        if(rx != rows[x].end()) {
            int nx = (*rx).first, ny = (*rx).second;
            grid[nx][ny] = 0;
            rows[nx].erase({nx, ny});
            cols[ny].erase({nx, ny});
            update(nx, ny, -1, 0);
            update(nx, ny, 1, 0);
            update(nx, ny, 0, -1);
            update(nx, ny, 0, 1);
        }
        auto cy = cols[y].lower_bound({x, y});
        if(cy != cols[y].begin()) {
            --cy;
            int nx = (*cy).first, ny = (*cy).second;
            grid[nx][ny] = 0;
            rows[nx].erase({nx, ny});
            cols[ny].erase({nx, ny});
            update(nx, ny, -1, 0);
            update(nx, ny, 1, 0);
            update(nx, ny, 0, -1);
            update(nx, ny, 0, 1);
        }
        cy = cols[y].upper_bound({x, y});
        if(cy != cols[y].end()) {
            int nx = (*cy).first, ny = (*cy).second;
            grid[nx][ny] = 0;
            rows[nx].erase({nx, ny});
            cols[ny].erase({nx, ny});
            update(nx, ny, -1, 0);
            update(nx, ny, 1, 0);
            update(nx, ny, 0, -1);
            update(nx, ny, 0, 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            rows[i].insert({i, j}), cols[j].insert({i, j});

    while(q--) {
        int x, y;
        cin >> x >> y;
        detonate(x, y);
    }

    int ans = 0;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            if(grid[i][j])
                ++ans;

    cout << ans << '\n';

    return 0;
}