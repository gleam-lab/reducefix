#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
            // Left
            for (int j = c - 1; j >= 0; --j) {
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    break;
                }
            }
            // Right
            for (int j = c + 1; j < W; ++j) {
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    break;
                }
            }
            // Up
            for (int i = r - 1; i >= 0; --i) {
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    break;
                }
            }
            // Down
            for (int i = r + 1; i < H; ++i) {
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    break;
                }
            }
        }
    }
    cout << (H * W - broken) << endl;
    
    return 0;
}