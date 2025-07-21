#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    int count = h * w;
    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if(grid[r][c]) {
            grid[r][c] = false;
            count--;
        } else {
            bool flag = true;
            for(int i = r - 1; i >= 0; i--) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                    count--;
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int i = r + 1; i < h; i++) {
                    if(grid[i][c]) {
                        grid[i][c] = false;
                        count--;
                        break;
                    }
                }
            }
            flag = true;
            for(int j = c - 1; j >= 0; j--) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                    count--;
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int j = c + 1; j < w; j++) {
                    if(grid[r][j]) {
                        grid[r][j] = false;
                        count--;
                        break;
                    }
                }
            }
        }
    }
    cout << count << "\n";
    return 0;
}