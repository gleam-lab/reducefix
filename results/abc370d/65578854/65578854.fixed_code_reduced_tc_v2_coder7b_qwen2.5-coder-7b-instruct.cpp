#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int walls = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R, --C;

        if (grid[R][C]) {
            grid[R][C] = false;
            walls--;

            // Check up
            for (int i = R - 1; i >= 0 && !grid[i][C]; --i) {
                walls--;
                grid[i][C] = true;
            }

            // Check down
            for (int i = R + 1; i < H && !grid[i][C]; ++i) {
                walls--;
                grid[i][C] = true;
            }

            // Check left
            for (int j = C - 1; j >= 0 && !grid[R][j]; --j) {
                walls--;
                grid[R][j] = true;
            }

            // Check right
            for (int j = C + 1; j < W && !grid[R][j]; ++j) {
                walls--;
                grid[R][j] = true;
            }
        }
    }

    cout << walls << '\n';
    return 0;
}