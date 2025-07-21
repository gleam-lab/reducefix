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
    
    // Each row and column stores the set of columns/rows that still have walls
    vector<set<int>> rows(H), cols(W);
    rep(i, H) {
        rep(j, W) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    ll total_destroyed = 0;

    auto destroy = [&](int r, int c) {
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            total_destroyed++;
        }
    };

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at (R, C), destroy it and continue
        if (rows[R].count(C)) {
            destroy(R, C);
            continue;
        }

        // Up and Down in column C
        auto& col_set = cols[C];
        auto it = col_set.lower_bound(R);

        // Look up (first wall above R)
        if (it != col_set.begin()) {
            --it;
            int up = *it;
            destroy(up, C);
        }

        // Look down (first wall below R)
        it = col_set.lower_bound(R);
        if (++it != col_set.end()) {
            int down = *it;
            destroy(down, C);
        }

        // Left and Right in row R
        auto& row_set = rows[R];
        auto jt = row_set.lower_bound(C);

        // Look left (first wall to the left of C)
        if (jt != row_set.begin()) {
            --jt;
            int left = *jt;
            destroy(R, left);
        }

        // Look right (first wall to the right of C)
        jt = row_set.lower_bound(C);
        if (++jt != row_set.end()) {
            int right = *jt;
            destroy(R, right);
        }
    }

    cout << (ll)H * (ll)W - total_destroyed << endl;
    return 0;
}