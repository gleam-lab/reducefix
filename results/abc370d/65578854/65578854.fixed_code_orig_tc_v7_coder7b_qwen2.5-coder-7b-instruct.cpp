#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int walls = H * W;

    while(Q--) {
        int R, C;
        cin >> R >> C;
        --R, --C;

        if(grid[R][C]) {
            grid[R][C] = false;
            --walls;
            continue;
        }

        // Destroy walls above R
        for(int i = R - 1; i >= 0; --i) {
            if(!grid[i][C]) break;
            grid[i][C] = false;
            --walls;
        }

        // Destroy walls below R
        for(int i = R + 1; i < H; ++i) {
            if(!grid[i][C]) break;
            grid[i][C] = false;
            --walls;
        }

        // Destroy walls to the left of C
        for(int j = C - 1; j >= 0; --j) {
            if(!grid[R][j]) break;
            grid[R][j] = false;
            --walls;
        }

        // Destroy walls to the right of C
        for(int j = C + 1; j < W; ++j) {
            if(!grid[R][j]) break;
            grid[R][j] = false;
            --walls;
        }
    }

    cout << walls << '\n';

    return 0;
}