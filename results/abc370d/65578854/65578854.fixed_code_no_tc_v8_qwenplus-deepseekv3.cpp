#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H + 2); // 1-based indexing
    vector<set<int>> col(W + 2); // 1-based indexing
    rep2(i, 1, H + 1) {
        row[i].insert(0);
        row[i].insert(W + 1);
    }
    rep2(j, 1, W + 1) {
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
    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            erase(R, C);
            continue;
        }
        // Up
        auto it = col[C].lower_bound(R);
        it--;
        erase(*it, C);
        // Down
        it = col[C].lower_bound(R);
        erase(*it, C);
        // Left
        it = row[R].lower_bound(C);
        it--;
        erase(R, *it);
        // Right
        it = row[R].lower_bound(C);
        erase(R, *it);
    }
    cout << ans - cnt << endl;
    return 0;
}