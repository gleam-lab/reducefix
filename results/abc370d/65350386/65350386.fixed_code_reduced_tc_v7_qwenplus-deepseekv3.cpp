#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
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

    int remaining = h * w;

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        auto& row_set = rows[r];
        auto& col_set = cols[c];

        if (row_set.count(c)) {
            row_set.erase(c);
            col_set.erase(r);
            remaining--;
        } else {
            // Up
            auto it_up = col_set.lower_bound(r);
            if (it_up != col_set.begin()) {
                --it_up;
                int i = *it_up;
                rows[i].erase(c);
                cols[c].erase(i);
                remaining--;
            }

            // Down
            auto it_down = col_set.lower_bound(r);
            if (it_down != col_set.end()) {
                int i = *it_down;
                rows[i].erase(c);
                cols[c].erase(i);
                remaining--;
            }

            // Left
            auto it_left = row_set.lower_bound(c);
            if (it_left != row_set.begin()) {
                --it_left;
                int j = *it_left;
                rows[r].erase(j);
                cols[j].erase(r);
                remaining--;
            }

            // Right
            auto it_right = row_set.lower_bound(c);
            if (it_right != row_set.end()) {
                int j = *it_right;
                rows[r].erase(j);
                cols[j].erase(r);
                remaining--;
            }
        }
    }

    cout << remaining << "\n";
    return 0;
}