#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : false); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : false); }

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H), col(W);
    
    // Initialize sets with wall positions
    rep(i, H) rep(j, W) {
        row[i].insert(j);
        col[j].insert(i);
    }

    auto destroy = [&](int r, int c) {
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            return true;
        }
        return false;
    };

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (destroy(R, C)) continue;

        // Up
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            it--;
            destroy(*it, C);
        }

        // Down
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            destroy(*it, C);
        }

        // Left
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            it--;
            destroy(R, *it);
        }

        // Right
        it = row[R].lower_bound(C);
        if (it != row[R].end()) {
            destroy(R, *it);
        }
    }

    ll remaining = 0;
    rep(i, H) remaining += row[i].size();
    cout << remaining << endl;

    return 0;
}