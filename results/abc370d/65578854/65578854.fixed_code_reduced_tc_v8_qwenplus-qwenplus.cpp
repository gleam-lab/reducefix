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
    vector<set<int>> row(W), col(H);
    
    rep(i, H) {
        rep(j, W) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    ll total_walls = H * W;

    auto destroy = [&](int r, int c) {
        if (col[r].count(c)) {
            total_walls--;
            col[r].erase(c);
            row[c].erase(r);
        }
    };

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Try to destroy wall at (R, C)
        if (col[R].count(C)) {
            destroy(R, C);
            continue;
        }

        // Up
        auto it = col[R].lower_bound(C);
        if (it != col[R].begin()) {
            it--;
            int c = *it;
            destroy(R, c);
        }

        // Down
        it = col[R].lower_bound(C);
        if (it != col[R].end()) {
            int c = *it;
            destroy(R, c);
        }

        // Left
        auto it2 = row[C].lower_bound(R);
        if (it2 != row[C].begin()) {
            it2--;
            int r = *it2;
            destroy(r, C);
        }

        // Right
        it2 = row[C].lower_bound(R);
        if (it2 != row[C].end()) {
            int r = *it2;
            destroy(r, C);
        }
    }

    cout << total_walls << endl;
    return 0;
}