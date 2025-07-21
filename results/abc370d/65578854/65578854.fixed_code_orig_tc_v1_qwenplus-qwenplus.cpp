#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : false); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : false); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rowWalls(H), colWalls(W);
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            rowWalls[r].insert(c);
            colWalls[c].insert(r);
        }
    }

    ll remaining = (ll)H * W;

    auto destroy = [&](int r, int c) {
        if (rowWalls[r].erase(c), colWalls[c].erase(r)) {
            remaining--;
            return true;
        }
        return false;
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If wall exists at (R,C), destroy it
        if (rowWalls[R].count(C)) {
            destroy(R, C);
            continue;
        }

        // Up
        auto it = colWalls[C].lower_bound(R);
        if (it != colWalls[C].begin()) {
            it--;
            int tr = *it;
            destroy(tr, C);
        }

        // Down
        it = colWalls[C].lower_bound(R);
        if (++it != colWalls[C].end()) {
            int br = *it;
            destroy(br, C);
        }

        // Left
        it = rowWalls[R].lower_bound(C);
        if (it != rowWalls[R].begin()) {
            it--;
            int lc = *it;
            destroy(R, lc);
        }

        // Right
        it = rowWalls[R].lower_bound(C);
        if (++it != rowWalls[R].end()) {
            int rc = *it;
            destroy(R, rc);
        }
    }

    cout << remaining << endl;
    return 0;
}