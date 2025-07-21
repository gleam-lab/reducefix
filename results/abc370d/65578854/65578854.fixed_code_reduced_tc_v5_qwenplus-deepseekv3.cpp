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
    vector<set<int>> row(H), col(W);
    rep(i, H) rep(j, W) {
        row[i].insert(j);
        col[j].insert(i);
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
        R--; C--;
        if (row[R].count(C)) {
            erase(R, C);
            continue;
        }
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            it--;
            erase(*it, C);
        }
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            erase(*it, C);
        }
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            it--;
            erase(R, *it);
        }
        it = row[R].lower_bound(C);
        if (it != row[R].end()) {
            erase(R, *it);
        }
    }
    cout << ans - cnt << endl;
    return 0;
}