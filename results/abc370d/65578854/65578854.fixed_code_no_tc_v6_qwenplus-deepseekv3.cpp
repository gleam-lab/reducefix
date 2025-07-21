#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
    rep(i, H) rep(j, W) {
        row[i + 1].insert(j + 1);
        col[j + 1].insert(i + 1);
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
    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            erase(R, C);
            continue;
        }
        auto it = col[C].lower_bound(R);
        int up = *prev(it);
        int down = *it;
        it = row[R].lower_bound(C);
        int left = *prev(it);
        int right = *it;
        if (up != 0) erase(up, C);
        if (down != H + 1) erase(down, C);
        if (left != 0) erase(R, left);
        if (right != W + 1) erase(R, right);
    }
    cout << ans - cnt << endl;
    return 0;
}