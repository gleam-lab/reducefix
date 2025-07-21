#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> walls(H, vector<bool>(W, true));
    vector<vector<int>> left(H, vector<int>(W));
    vector<vector<int>> right(H, vector<int>(W));
    vector<vector<int>> up(H, vector<int>(W));
    vector<vector<int>> down(H, vector<int>(W));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            left[i][j] = j - 1;
            right[i][j] = j + 1;
            up[i][j] = i - 1;
            down[i][j] = i + 1;
        }
    }
    
    int broken = 0;
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C;
        
        if (walls[R][C]) {
            walls[R][C] = false;
            ++broken;
            
            if (left[R][C] != -1) {
                right[R][left[R][C]] = right[R][C];
            }
            if (right[R][C] < W) {
                left[R][right[R][C]] = left[R][C];
            }
            if (up[R][C] != -1) {
                down[up[R][C]][C] = down[R][C];
            }
            if (down[R][C] < H) {
                up[down[R][C]][C] = up[R][C];
            }
        } else {
            if (left[R][C] != -1 && walls[R][left[R][C]]) {
                walls[R][left[R][C]] = false;
                ++broken;
                if (left[R][left[R][C]] != -1) {
                    right[R][left[R][left[R][C]]] = right[R][left[R][C]];
                }
                left[R][C] = left[R][left[R][C]];
            }
            if (right[R][C] < W && walls[R][right[R][C]]) {
                walls[R][right[R][C]] = false;
                ++broken;
                if (right[R][right[R][C]] < W) {
                    left[R][right[R][right[R][C]]] = left[R][right[R][C]];
                }
                right[R][C] = right[R][right[R][C]];
            }
            if (up[R][C] != -1 && walls[up[R][C]][C]) {
                walls[up[R][C]][C] = false;
                ++broken;
                if (up[up[R][C]][C] != -1) {
                    down[up[up[R][C]][C]][C] = down[up[R][C]][C];
                }
                up[R][C] = up[up[R][C]][C];
            }
            if (down[R][C] < H && walls[down[R][C]][C]) {
                walls[down[R][C]][C] = false;
                ++broken;
                if (down[down[R][C]][C] < H) {
                    up[down[down[R][C]][C]][C] = up[down[R][C]][C];
                }
                down[R][C] = down[down[R][C]][C];
            }
        }
    }
    
    cout << H * W - broken << "\n";
    
    return 0;
}