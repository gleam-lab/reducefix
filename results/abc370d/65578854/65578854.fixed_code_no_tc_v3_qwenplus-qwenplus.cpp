#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row, we maintain a set of columns that still have walls
    vector<set<int>> row(H);
    // For each column, we maintain a set of rows that still have walls
    vector<set<int>> col(W);

    // Initialize all walls present
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row[r].insert(c);
            col[c].insert(r);
        }
    }

    ll remaining = (ll)H * W;

    auto destroy = [&](int r, int c) {
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        }
    };

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at the current cell, destroy it and end
        if (row[r].count(c)) {
            destroy(R, C);
            continue;
        }

        // Look up
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            --it;
            destroy(*it, C);
        }

        // Look down
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            destroy(*it, C);
        }

        // Look left
        auto& cols = row[R];
        auto jt = cols.lower_bound(C);
        if (jt != cols.begin()) {
            --jt;
            destroy(R, *jt);
        }

        // Look right
        jt = cols.lower_bound(C);
        if (jt != cols.end()) {
            destroy(R, *jt);
        }
    }

    cout << remaining << endl;
    return 0;
}