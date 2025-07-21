#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<pair<int, int>> bombs;

    for(int qi=0; qi<q; qi++) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        bombs.emplace_back(r, c);
    }

    for(auto& [r, c] : bombs) {
        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            for(int dr=-1; dr<=1; dr+=2) {
                for(int dc=-1; dc<=1; dc+=2) {
                    int nr = r + dr, nc = c + dc;
                    while(nr >= 0 && nr < h && nc >= 0 && nc < w) {
                        if(grid[nr][nc]) {
                            grid[nr][nc] = false;
                            break;
                        }
                        nr += dr;
                        nc += dc;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(auto& row : grid) {
        ans += count(row.begin(), row.end(), true);
    }

    cout << ans << endl;

    return 0;
}