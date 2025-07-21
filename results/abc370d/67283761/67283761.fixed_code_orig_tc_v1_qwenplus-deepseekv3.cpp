#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));

    int broken = 0;
    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (map[r][c]) {
            ++broken;
            map[r][c] = false;
        } else {
            // Check up
            for (int i = r - 1; i >= 0; --i) {
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    break;
                }
            }
            // Check down
            for (int i = r + 1; i < H; ++i) {
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    break;
                }
            }
            // Check left
            for (int j = c - 1; j >= 0; --j) {
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    break;
                }
            }
            // Check right
            for (int j = c + 1; j < W; ++j) {
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    break;
                }
            }
        }
    }
    cout << (H * W - broken) << endl;

    return 0;
}