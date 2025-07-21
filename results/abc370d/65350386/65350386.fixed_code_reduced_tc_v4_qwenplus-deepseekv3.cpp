#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    rep(i, h) {
        rep(j, w) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                it_up--;
                int i = *it_up;
                rows[i].erase(c);
                cols[c].erase(it_up);
            }

            // Down
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                int i = *it_down;
                rows[i].erase(c);
                cols[c].erase(it_down);
            }

            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                it_left--;
                int j = *it_left;
                rows[r].erase(j);
                cols[j].erase(r);
            }

            // Right
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                int j = *it_right;
                rows[r].erase(j);
                cols[j].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, h) ans += rows[i].size();
    cout << ans << "\n";

    return 0;
}