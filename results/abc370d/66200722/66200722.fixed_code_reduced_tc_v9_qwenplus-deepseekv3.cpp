#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    set<pair<int, int>> destroyed;
    int remaining = H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based indexing
        
        if (destroyed.count({R, C})) {
            // No wall here, so destroy first walls in four directions
            // Up
            for (int i = R - 1; i >= 0; --i) {
                if (!destroyed.count({i, C})) {
                    destroyed.insert({i, C});
                    remaining--;
                    break;
                }
            }
            // Down
            for (int i = R + 1; i < H; ++i) {
                if (!destroyed.count({i, C})) {
                    destroyed.insert({i, C});
                    remaining--;
                    break;
                }
            }
            // Left
            for (int j = C - 1; j >= 0; --j) {
                if (!destroyed.count({R, j})) {
                    destroyed.insert({R, j});
                    remaining--;
                    break;
                }
            }
            // Right
            for (int j = C + 1; j < W; ++j) {
                if (!destroyed.count({R, j})) {
                    destroyed.insert({R, j});
                    remaining--;
                    break;
                }
            }
        } else {
            // Destroy the wall at (R, C)
            destroyed.insert({R, C});
            remaining--;
        }
    }
    
    cout << remaining << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}