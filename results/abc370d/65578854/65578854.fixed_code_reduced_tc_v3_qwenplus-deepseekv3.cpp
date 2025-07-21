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
    vector<set<int>> row(H + 1), col(W + 1);
    rep2(i, 1, H + 1) rep2(j, 1, W + 1) {
        row[i].insert(j);
        col[j].insert(i);
    }
    ll total = H * W;
    ll removed = 0;
    auto erase_wall = [&](int r, int c) {
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            removed++;
        }
    };
    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            erase_wall(R, C);
            continue;
        }
        // Up
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            --it;
            erase_wall(*it, C);
            it++;
        }
        // Down
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            erase_wall(*it, C);
        }
        // Left
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            --it;
            erase_wall(R, *it);
            it++;
        }
        // Right
        it = row[R].lower_bound(C);
        if (it != row[R].end()) {
            erase_wall(R, *it);
        }
    }
    cout << total - removed << endl;
    return 0;
}