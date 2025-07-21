#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, keep track of the walls using sets
    vector<set<int>> rows(H + 1), cols(W + 1);

    // Initialize all walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        }
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (rows[r].count(c)) {
            // Cell has a wall, destroy it and end
            destroy(r, c);
        } else {
            // Destroy first wall in each direction
            // Right
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                destroy(r, *it);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                if (*it < c) {
                    destroy(r, *it);
                }
            }

            // Down
            auto jt = cols[c].lower_bound(r);
            if (jt != cols[c].end()) {
                destroy(*jt, c);
            }

            // Up
            jt = cols[c].lower_bound(r);
            if (jt != cols[c].begin()) {
                --jt;
                if (*jt < r) {
                    destroy(*jt, c);
                }
            }
        }
    }

    ll remaining = 0;
    for (int i = 1; i <= H; ++i) {
        remaining += rows[i].size();
    }
    cout << remaining << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}