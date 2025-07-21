#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> rows(h), cols(w);
    rep(i, h) rep(j, w) {
        rows[i].insert(j);
        cols[j].insert(i);
    }

    int ans = h * w;

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            ans--;
        } else {
            // Check up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                it_up--;
                int i = *it_up;
                rows[i].erase(c);
                cols[c].erase(i);
                ans--;
            }

            // Check down
            auto it_down = cols[c].upper_bound(r);
            if (it_down != cols[c].end()) {
                int i = *it_down;
                rows[i].erase(c);
                cols[c].erase(i);
                ans--;
            }

            // Check left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                it_left--;
                int j = *it_left;
                rows[r].erase(j);
                cols[j].erase(r);
                ans--;
            }

            // Check right
            auto it_right = rows[r].upper_bound(c);
            if (it_right != rows[r].end()) {
                int j = *it_right;
                rows[r].erase(j);
                cols[j].erase(r);
                ans--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}