#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // For each row, keep a sorted set of columns that still have walls
    vector<set<int>> rows(H);
    // For each column, keep a sorted set of rows that still have walls
    vector<set<int>> cols(W);

    // Initialize all walls to be present
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            rows[r].insert(c);
            cols[c].insert(r);
        }
    }

    ll remaining = (ll)H * W;

    auto destroy = [&](int r, int c) {
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at (R, C), destroy it and continue
        if (rows[R].count(C)) {
            destroy(R, C);
            continue;
        }

        // Look up in the column C below R
        auto it = cols[C].lower_bound(R);
        if (it != cols[C].begin()) {
            --it;
            destroy(*it, C);
        }

        // Look down in the column C above R
        it = cols[C].lower_bound(R);
        if (it != cols[C].end() && *it > R) {
            destroy(*it, C);
        }

        // Look left in the row R
        it = rows[R].lower_bound(C);
        if (it != rows[R].begin()) {
            --it;
            destroy(R, *it);
        }

        // Look right in the row R
        it = rows[R].lower_bound(C);
        if (it != rows[R].end() && *it > C) {
            destroy(R, *it);
        }
    }

    cout << remaining << endl;
    return 0;
}