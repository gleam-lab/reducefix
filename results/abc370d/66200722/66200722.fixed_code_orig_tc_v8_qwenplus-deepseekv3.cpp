#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> walls(H + 1, vector<bool>(W + 1, true));
    long long remaining = (long long)H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (walls[R][C]) {
            walls[R][C] = false;
            remaining--;
        } else {
            // Check up
            for (int i = R - 1; i >= 1; --i) {
                if (walls[i][C]) {
                    walls[i][C] = false;
                    remaining--;
                    break;
                }
            }
            // Check down
            for (int i = R + 1; i <= H; ++i) {
                if (walls[i][C]) {
                    walls[i][C] = false;
                    remaining--;
                    break;
                }
            }
            // Check left
            for (int j = C - 1; j >= 1; --j) {
                if (walls[R][j]) {
                    walls[R][j] = false;
                    remaining--;
                    break;
                }
            }
            // Check right
            for (int j = C + 1; j <= W; ++j) {
                if (walls[R][j]) {
                    walls[R][j] = false;
                    remaining--;
                    break;
                }
            }
        }
    }
    
    cout << remaining << '\n';
    
    return 0;
}