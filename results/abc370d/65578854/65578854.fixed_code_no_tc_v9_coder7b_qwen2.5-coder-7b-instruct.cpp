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
    vector<bool> X(H * W, true), Y(H * W, true);
    ll ans = H * W;
    ll cnt = 0;
    auto erase = [&](int r, int c) {
        cnt++;
        X[r * W + c] = false;
        Y[c * H + r] = false;
    };
    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        if (X[R * W + C]) {
            erase(R, C);
            continue;
        }
        int idx = R * W + C;
        // 上
        while (idx >= 0 && !Y[idx % H]) idx -= W;
        if (idx >= 0) erase(idx / W, idx % W);

        idx = R * W + C;
        // 下
        while (idx < H * W && !Y[idx % H]) idx += W;
        if (idx < H * W) erase(idx / W, idx % W);

        idx = R * W + C;
        // 左
        while (idx >= 0 && !X[idx / W]) idx -= 1;
        if (idx >= 0) erase(idx / W, idx % W);

        idx = R * W + C;
        // 右
        while (idx < H * W && !X[idx / W]) idx += 1;
        if (idx < H * W) erase(idx / W, idx % W);
    }
    cout << ans - cnt << endl;
    return 0;
}