#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> X(H + 2), Y(W + 2);  // 1-based indexing and extra boundary
    rep2(i, 1, H + 1) rep2(j, 1, W + 1) {
        X[i].insert(j);
        Y[j].insert(i);
    }
    ll ans = (ll)H * W;
    ll cnt = 0;
    auto erase = [&](int r, int c) {
        if (X[r].count(c)) {
            cnt++;
            X[r].erase(c);
            Y[c].erase(r);
        }
    };
    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        if (X[R].count(C)) {
            erase(R, C);
            continue;
        }
        // Up
        auto it_up = Y[C].lower_bound(R);
        if (it_up != Y[C].begin()) {
            --it_up;
            erase(*it_up, C);
        }
        // Down
        auto it_down = Y[C].lower_bound(R);
        if (it_down != Y[C].end()) {
            erase(*it_down, C);
        }
        // Left
        auto it_left = X[R].lower_bound(C);
        if (it_left != X[R].begin()) {
            --it_left;
            erase(R, *it_left);
        }
        // Right
        auto it_right = X[R].lower_bound(C);
        if (it_right != X[R].end()) {
            erase(R, *it_right);
        }
    }
    cout << ans - cnt << endl;
    return 0;
}