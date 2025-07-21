#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    int broken = 0;

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (map[r][c]) {
            map[r][c] = false;
            ++broken;
        } else {
            // Up
            for (int i = r - 1; i >= 0; --i) {
                if (map[i][c]) {
                    map[i][c] = false;
                    ++broken;
                    break;
                }
            }
            // Down
            for (int i = r + 1; i < H; ++i) {
                if (map[i][c]) {
                    map[i][c] = false;
                    ++broken;
                    break;
                }
            }
            // Left
            for (int j = c - 1; j >= 0; --j) {
                if (map[r][j]) {
                    map[r][j] = false;
                    ++broken;
                    break;
                }
            }
            // Right
            for (int j = c + 1; j < W; ++j) {
                if (map[r][j]) {
                    map[r][j] = false;
                    ++broken;
                    break;
                }
            }
        }
    }
    cout << (H * W - broken) << endl;
    return 0;
}