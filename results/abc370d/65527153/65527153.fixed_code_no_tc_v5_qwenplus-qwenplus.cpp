#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
using grid = vector<vector<T>>;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // We'll represent the presence of walls using sets for each row and column
    vector<set<int>> row(W + 1), col(H + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        // Check if there's a wall at (r, c)
        auto it = col[r].find(c);
        if (it != col[r].end()) {
            // Wall exists, remove it
            col[r].erase(c);
            row[c].erase(r);
            continue;
        }

        // Directions: up, down, left, right
        // For vertical directions (up, down), we search in row `c` for values near `r`
        auto &vertical = row[c];
        // Up: find the first wall above r
        auto vit = vertical.lower_bound(r);
        if (vit != vertical.begin()) {
            vit--;
            int u = *vit;
            col[u].erase(c);
            vertical.erase(vit);
        }

        // Down: find the first wall below r
        vit = vertical.lower_bound(r);
        if (vit != vertical.end()) {
            int d = *vit;
            col[d].erase(c);
            vertical.erase(vit);
        }

        // For horizontal directions (left, right), we search in column `r` for values near `c`
        auto &horizontal = col[r];
        // Left: find the first wall to the left of c
        auto hit = horizontal.lower_bound(c);
        if (hit != horizontal.begin()) {
            hit--;
            int l = *hit;
            row[l].erase(r);
            horizontal.erase(hit);
        }

        // Right: find the first wall to the right of c
        hit = horizontal.lower_bound(c);
        if (hit != horizontal.end()) {
            int ri = *hit;
            row[ri].erase(r);
            horizontal.erase(hit);
        }
    }

    ll remaining = 0;
    for (int i = 1; i <= H; ++i) {
        remaining += col[i].size();
    }
    cout << remaining << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}