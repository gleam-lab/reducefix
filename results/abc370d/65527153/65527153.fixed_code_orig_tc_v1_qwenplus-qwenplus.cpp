#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(W + 1), col(H + 1); // row[c] contains sorted rows with walls in column c; col[r] contains sorted columns with walls in row r
    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            row[c].insert(r);
            col[r].insert(c);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row[c].find(r) == row[c].end()) { // No wall at (r,c)
            // Look up/down in column c
            auto& rs = row[c];
            auto it = rs.lower_bound(r);
            if (it != rs.end()) rs.erase(it); // down
            if (it != rs.begin()) {
                --it;
                rs.erase(it); // up
            }

            // Look left/right in row r
            auto& cs = col[r];
            it = cs.lower_bound(c);
            if (it != cs.end()) cs.erase(it); // right
            if (it != cs.begin()) {
                --it;
                cs.erase(it); // left
            }
        } else {
            // Remove the wall at (r,c)
            row[c].erase(r);
            col[r].erase(c);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += col[i].size();
    }
    cout << ans << '\n';

    return 0;
}