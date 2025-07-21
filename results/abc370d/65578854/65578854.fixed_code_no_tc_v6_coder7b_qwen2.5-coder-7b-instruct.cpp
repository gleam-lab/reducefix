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
    vector<bool> X(H * W, true);
    vector<bool> Y(H * W, true);
    ll ans = H * W;
    ll cnt = 0;

    auto index = [&](int r, int c) {
        return r * W + c;
    };

    auto erase = [&](int idx) {
        cnt++;
        X[idx] = false;
        Y[idx] = false;
    };

    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        int idx = index(R, C);
        if (X[idx]) {
            erase(idx);
            continue;
        }

        int up = R - 1, down = R + 1, left = C - 1, right = C + 1;
        while (up >= 0 && !X[index(up, C)]) --up;
        while (down < H && !X[index(down, C)]) ++down;
        while (left >= 0 && !Y[index(R, left)]) --left;
        while (right < W && !Y[index(R, right)]) ++right;

        if (up >= 0) erase(index(up, C));
        if (down < H) erase(index(down, C));
        if (left >= 0) erase(index(R, left));
        if (right < W) erase(index(R, right));
    }

    cout << ans - cnt << endl;
    return 0;
}