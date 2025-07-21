#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H), col(W);

    // Initialize each row and column with all columns/rows present
    rep(i, H) {
        for (int j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at the current cell
        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // Up direction
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                it--;
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
            }

            // Down direction
            it = col[C].lower_bound(R);
            if (it != col[C].end()) {
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
            }

            // Left direction
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                it--;
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
            }

            // Right direction
            it = row[R].lower_bound(C);
            if (it != row[R].end()) {
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
            }
        }
    }

    // Count remaining walls
    ll remaining = 0;
    rep(i, H) remaining += row[i].size();
    cout << remaining << endl;

    return 0;
}