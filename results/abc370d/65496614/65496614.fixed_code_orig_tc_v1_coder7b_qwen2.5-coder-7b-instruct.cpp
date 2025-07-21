#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n) ; ++i)
#define rep1(i,n) for(int i = 1; i <= (int)(n) ; ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (int)n-1; i > 0 ; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vvi grid(h, vi(w, 1));
    queue<pair<int, int>> walls;

    rep(i, h) rep(j, w) if(grid[i][j]) walls.push({i, j});

    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(!grid[r][c]) continue;

        grid[r][c] = 0;
        walls.pop();

        if(r > 0 && grid[r-1][c]) {
            walls.push({r-1, c});
            grid[r-1][c] = 0;
        }
        if(r < h-1 && grid[r+1][c]) {
            walls.push({r+1, c});
            grid[r+1][c] = 0;
        }
        if(c > 0 && grid[r][c-1]) {
            walls.push({r, c-1});
            grid[r][c-1] = 0;
        }
        if(c < w-1 && grid[r][c+1]) {
            walls.push({r, c+1});
            grid[r][c+1] = 0;
        }
    }

    cout << walls.size() << endl;

    return 0;
}