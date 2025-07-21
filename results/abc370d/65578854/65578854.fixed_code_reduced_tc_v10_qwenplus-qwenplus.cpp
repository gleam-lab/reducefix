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

    // Initialize each row and column with all wall positions
    rep(i, H) rep(j, W) {
        row[i].insert(j);
        col[j].insert(i);
    }

    auto destroyWall = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (row[R].count(C)) {
            // Wall exists at (R, C), destroy it
            destroyWall(R, C);
        } else {
            // Destroy first wall above
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                it--;
                destroyWall(*it, C);
            }

            // Destroy first wall below
            it = col[C].lower_bound(R);
            if (it != col[C].end()) {
                destroyWall(*it, C);
            }

            // Destroy first wall left
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                it--;
                destroyWall(R, *it);
            }

            // Destroy first wall right
            it = row[R].lower_bound(C);
            if (it != row[R].end()) {
                destroyWall(R, *it);
            }
        }
    }

    // Count remaining walls
    ll total = 0;
    rep(i, H) total += row[i].size();
    cout << total << endl;

    return 0;
}