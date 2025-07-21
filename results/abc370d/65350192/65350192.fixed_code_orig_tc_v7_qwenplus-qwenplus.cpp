#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using pii = pair<int, int>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1 << 30;

int H, W, Q;

// For each row and column, maintain a set of available wall positions
vector<set<int>> rows, cols;

void breakWall(int r, int c) {
    // Remove from row and col sets if exists
    auto rit = rows[r].find(c);
    if (rit != rows[r].end()) {
        rows[r].erase(rit);
    }

    auto cit = cols[c].find(r);
    if (cit != cols[c].end()) {
        cols[c].erase(cit);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Q;

    rows.resize(H);
    cols.resize(W);

    // Initialize all walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at the position
        if (cols[c].count(r)) {
            // Directly break this wall
            breakWall(r, c);
        } else {
            // Try to find nearest walls in 4 directions

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int up_r = *it;
                breakWall(up_r, c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int down_r = *it;
                breakWall(down_r, c);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                int left_c = *jt;
                breakWall(r, left_c);
            }

            // Right
            jt = rows[r].lower_bound(c);
            if (jt != rows[r].end()) {
                int right_c = *jt;
                breakWall(r, right_c);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += rows[i].size();
    }

    cout << ans << '\n';

    return 0;
}