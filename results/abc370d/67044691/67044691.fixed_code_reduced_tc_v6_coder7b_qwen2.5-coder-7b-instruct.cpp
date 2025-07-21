#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while(q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            bool found = false;
            for(int i = r - 1; i >= 0; --i) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                    found = true;
                    break;
                }
            }
            if(!found) {
                for(int i = r + 1; i < h; ++i) {
                    if(grid[i][c]) {
                        grid[i][c] = false;
                        break;
                    }
                }
            }
            found = false;
            for(int j = c - 1; j >= 0; --j) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                    found = true;
                    break;
                }
            }
            if(!found) {
                for(int j = c + 1; j < w; ++j) {
                    if(grid[r][j]) {
                        grid[r][j] = false;
                        break;
                    }
                }
            }
        }
    }

    int count = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j]) ++count;
        }
    }

    cout << count << '\n';

    return 0;
}