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
    rep(i, H) rep(j, W) {
        row[i].insert(j);
        col[j].insert(i);
    }

    ll remaining = (ll)H * (ll)W;

    auto destroy = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there is a wall at the current cell
        if (row[R].count(C)) {
            destroy(R, C);
            remaining--;
            continue;
        }

        // Look up and down in the column
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            // Up direction
            int u = *(--it);
            destroy(u, C);
            remaining--;
        }

        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            // Down direction
            int d = *(it);
            if (d != R) { // avoid re-deleting if already handled
                destroy(d, C);
                remaining--;
            }
        }

        // Look left and right in the row
        auto jt = row[R].lower_bound(C);
        if (jt != row[R].begin()) {
            // Left direction
            int l = *(--jt);
            destroy(R, l);
            remaining--;
        }

        jt = row[R].lower_bound(C);
        if (jt != row[R].end()) {
            // Right direction
            int r = *(jt);
            if (r != C) { // avoid re-deleting if already handled
                destroy(R, r);
                remaining--;
            }
        }
    }

    cout << remaining << endl;
    return 0;
}