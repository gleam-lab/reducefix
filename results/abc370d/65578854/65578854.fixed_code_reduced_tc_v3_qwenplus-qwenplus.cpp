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
    
    // For each row and column, keep track of the walls using sets
    vector<set<int>> row(W), col(H);
    
    // Initialize sets with all positions
    rep(i, H) {
        rep(j, W) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    ll total_walls = H * W;
    set<pair<int, int>> destroyed;

    auto destroy = [&](int r, int c) {
        if (destroyed.count({r, c})) return;
        destroyed.insert({r, c});
        row[c].erase(r);
        col[r].erase(c);
        total_walls--;
    };

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (destroyed.count({R, C})) {
            // Bomb explodes in 4 directions
            // Up
            if (!col[R].empty()) {
                auto it = col[R].lower_bound(C);
                if (it != col[R].begin()) {
                    it--;
                    int c = *it;
                    destroy(R, c);
                }
            }

            // Down
            if (!col[R].empty()) {
                auto it = col[R].lower_bound(C);
                if (it != col[R].end()) {
                    int c = *it;
                    destroy(R, c);
                }
            }

            // Left
            if (!row[C].empty()) {
                auto it = row[C].lower_bound(R);
                if (it != row[C].begin()) {
                    it--;
                    int r = *it;
                    destroy(r, C);
                }
            }

            // Right
            if (!row[C].empty()) {
                auto it = row[C].lower_bound(R);
                if (it != row[C].end()) {
                    int r = *it;
                    destroy(r, C);
                }
            }
        } else {
            // Bomb at this cell has wall, destroy it
            destroy(R, C);
        }
    }

    cout << total_walls << endl;
    return 0;
}