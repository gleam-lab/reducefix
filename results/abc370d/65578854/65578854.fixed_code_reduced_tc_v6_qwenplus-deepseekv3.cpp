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
    vector<set<int>> row(H + 2), col(W + 2);
    rep(i, H + 2) {
        row[i].insert(0);
        row[i].insert(W + 1);
    }
    rep(j, W + 2) {
        col[j].insert(0);
        col[j].insert(H + 1);
    }
    ll ans = (ll)H * W;
    ll cnt = 0;
    auto erase = [&](int r, int c) {
        if (row[r].count(c)) {
            cnt++;
            row[r].erase(c);
            col[c].erase(r);
        }
    };
    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            erase(R, C);
        } else {
            // Up
            auto it = col[C].lower_bound(R);
            it--;
            if (*it != 0) {
                erase(*it, C);
            }
            // Down
            it = col[C].lower_bound(R);
            if (*it != H + 1) {
                erase(*it, C);
            }
            // Left
            it = row[R].lower_bound(C);
            it--;
            if (*it != 0) {
                erase(R, *it);
            }
            // Right
            it = row[R].lower_bound(C);
            if (*it != W + 1) {
                erase(R, *it);
            }
        }
    }
    cout << ans - cnt << endl;
    return 0;
}