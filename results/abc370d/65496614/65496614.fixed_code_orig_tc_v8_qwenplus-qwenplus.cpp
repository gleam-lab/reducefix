#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; --i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1 << 30;

// For each row and column, maintain ordered sets of wall positions
vector<set<int>> rows, cols;

int H, W;

void removeWall(int r, int c) {
    rows[r].erase(c);
    cols[c].erase(r);
}

bool hasWall(int r, int c) {
    return rows[r].find(c) != rows[r].end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> H >> W >> Q;

    // Initialize walls in rows and columns
    rows.resize(H + 2);
    cols.resize(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (hasWall(r, c)) {
            removeWall(r, c);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                removeWall(*it, c);
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                removeWall(*it, c);
            }

            // Left
            auto& row_set = rows[r];
            it = row_set.lower_bound(c);
            if (it != row_set.begin()) {
                --it;
                removeWall(r, *it);
            }

            // Right
            it = row_set.upper_bound(c);
            if (it != row_set.end()) {
                removeWall(r, *it);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += rows[i].size();
    }

    cout << ans << "\n";

    return 0;
}