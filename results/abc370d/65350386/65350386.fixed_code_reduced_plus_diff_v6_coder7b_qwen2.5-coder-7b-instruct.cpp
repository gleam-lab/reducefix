#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int qi = 0; qi < q; qi++) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;

        // Check above
        if (r > 0 && grid[r-1][c]) {
            pq.push({r-1, {c, 0}});
            grid[r-1][c] = false;
        }

        // Check below
        if (r < h-1 && grid[r+1][c]) {
            pq.push({r+1, {c, 0}});
            grid[r+1][c] = false;
        }

        // Check left
        if (c > 0 && grid[r][c-1]) {
            pq.push({r, {c-1, 0}});
            grid[r][c-1] = false;
        }

        // Check right
        if (c < w-1 && grid[r][c+1]) {
            pq.push({r, {c+1, 0}});
            grid[r][c+1] = false;
        }
    }

    while (!pq.empty()) {
        auto [r, p] = pq.top(); pq.pop();
        auto [c, dir] = p;

        if (!grid[r][c]) continue;

        grid[r][c] = false;

        // Check above
        if (dir == 0 && r > 0 && grid[r-1][c]) {
            pq.push({r-1, {c, 0}});
            grid[r-1][c] = false;
        }

        // Check below
        if (dir == 0 && r < h-1 && grid[r+1][c]) {
            pq.push({r+1, {c, 0}});
            grid[r+1][c] = false;
        }

        // Check left
        if (dir == 0 && c > 0 && grid[r][c-1]) {
            pq.push({r, {c-1, 0}});
            grid[r][c-1] = false;
        }

        // Check right
        if (dir == 0 && c < w-1 && grid[r][c+1]) {
            pq.push({r, {c+1, 0}});
            grid[r][c+1] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) count++;
        }
    }

    cout << count << '\n';
    return 0;
}