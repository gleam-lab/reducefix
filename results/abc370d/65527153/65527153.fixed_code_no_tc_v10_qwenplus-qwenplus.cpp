#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

const int INF = 0x3f3f3f3f;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // row_walls[r]: sorted set of columns in row r that still have walls
    vector<set<int>> row_walls(H + 1);
    // col_walls[c]: sorted set of rows in column c that still have walls
    vector<set<int>> col_walls(W + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    auto erase_cell = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        // If there's a wall at (r, c), destroy it and continue
        if (row_walls[r].count(c)) {
            erase_cell(r, c);
            continue;
        }

        // Look right along the row
        auto it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].end()) {
            erase_cell(r, *it);
        }

        // Look left along the row
        it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].begin()) {
            --it;
            erase_cell(r, *it);
        }

        // Look down in the column
        auto it2 = col_walls[c].lower_bound(r);
        if (it2 != col_walls[c].end()) {
            erase_cell(*it2, c);
        }

        // Look up in the column
        it2 = col_walls[c].lower_bound(r);
        if (it2 != col_walls[c].begin()) {
            --it2;
            erase_cell(*it2, c);
        }
    }

    long long remaining = 0;
    for (int i = 1; i <= H; ++i) {
        remaining += row_walls[i].size();
    }
    cout << remaining << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}