#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    ll ans = H * W;
    rep(itr, Q){
        int R, C;
        cin >> R >> C;
        R--; C--;
        if(grid[R][C]){
            grid[R][C] = false;
            ans--;
            // Check up
            rep2(i, 0, R){
                if(grid[i][C]){
                    grid[i][C] = false;
                    ans--;
                    break;
                }
            }
            // Check down
            rep2(i, R+1, H){
                if(grid[i][C]){
                    grid[i][C] = false;
                    ans--;
                    break;
                }
            }
            // Check left
            rep2(j, 0, C){
                if(grid[R][j]){
                    grid[R][j] = false;
                    ans--;
                    break;
                }
            }
            // Check right
            rep2(j, C+1, W){
                if(grid[R][j]){
                    grid[R][j] = false;
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}