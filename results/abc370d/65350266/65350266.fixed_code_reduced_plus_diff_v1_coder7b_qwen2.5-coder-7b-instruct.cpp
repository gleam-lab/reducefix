#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> cols(h), rows(w);

    rep(i, h) rep(j, w) {
        cols[i].insert(j);
        rows[j].insert(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (!cols[r].empty() && *cols[r].begin() == c) {
            cols[r].erase(cols[r].begin());
            rows[c].erase(rows[c].begin());
        } else {
            // Find the nearest wall above the current position
            auto it_up = cols[r].upper_bound(c);
            if (it_up != cols[r].begin()) {
                --it_up;
                if (*it_up == c) continue;
                cols[r].erase(it_up);
                rows[*it_up].erase(r);
            }

            // Find the nearest wall below the current position
            it_up = cols[r].upper_bound(c);
            if (it_up != cols[r].end()) {
                cols[r].erase(it_up);
                rows[*it_up].erase(r);
            }

            // Find the nearest wall to the left of the current position
            it_up = rows[c].upper_bound(r);
            if (it_up != rows[c].begin()) {
                --it_up;
                if (*it_up == r) continue;
                rows[c].erase(it_up);
                cols[*it_up].erase(c);
            }

            // Find the nearest wall to the right of the current position
            it_up = rows[c].upper_bound(r);
            if (it_up != rows[c].end()) {
                rows[c].erase(it_up);
                cols[*it_up].erase(c);
            }
        }
    }

    int ans = 0;
    rep(i, w) {
        ans += cols[i].size();
    }

    cout << ans << '\n';
    return 0;
}