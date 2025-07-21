#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    ll ans = H * W;
    
    auto destroy_walls = [&](int r, int c) {
        if (!grid[r][c]) return;  // If there is no wall, no need to do anything.
        grid[r][c] = false;
        ans--;
        
        // Destroy vertical walls
        for (int i = 0; i < W; i++) {
            if (i != c && grid[r][i]) {
                grid[r][i] = false;
                ans--;
            }
        }
        
        // Destroy horizontal walls
        for (int i = 0; i < H; i++) {
            if (i != r && grid[i][c]) {
                grid[i][c] = false;
                ans--;
            }
        }
    };

    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        destroy_walls(R, C);
    }
    
    cout << ans << endl;
    return 0;
}