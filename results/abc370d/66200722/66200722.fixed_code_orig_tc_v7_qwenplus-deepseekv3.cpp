#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    set<pair<int, int>> destroyed;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        
        if (destroyed.count({R, C})) {
            // Check up
            for (int i = R - 1; i >= 0; --i) {
                if (!destroyed.count({i, C})) {
                    destroyed.insert({i, C});
                    break;
                }
            }
            // Check down
            for (int i = R + 1; i < H; ++i) {
                if (!destroyed.count({i, C})) {
                    destroyed.insert({i, C});
                    break;
                }
            }
            // Check left
            for (int j = C - 1; j >= 0; --j) {
                if (!destroyed.count({R, j})) {
                    destroyed.insert({R, j});
                    break;
                }
            }
            // Check right
            for (int j = C + 1; j < W; ++j) {
                if (!destroyed.count({R, j})) {
                    destroyed.insert({R, j});
                    break;
                }
            }
        } else {
            destroyed.insert({R, C});
        }
    }
    
    cout << H * W - destroyed.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}