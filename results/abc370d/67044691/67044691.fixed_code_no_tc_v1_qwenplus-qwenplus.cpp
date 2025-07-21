#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> rows(h), cols(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        auto& row_set = rows[r];
        auto& col_set = cols[c];

        if (row_set.find(c) != row_set.end()) {
            // Wall exists here, just remove it
            row_set.erase(c);
            col_set.erase(r);
        } else {
            // Look in four directions

            // Up (in column c, less than r)
            auto up = col_set.lower_bound(r);
            if (up != col_set.begin()) {
                up--;
                int ur = *up;
                int uc = c;
                rows[ur].erase(uc);
                cols[uc].erase(ur);
            }

            // Down (in column c, greater than r)
            auto down = col_set.upper_bound(r);
            if (down != col_set.end()) {
                int dr = *down;
                int dc = c;
                rows[dr].erase(dc);
                cols[dc].erase(dr);
            }

            // Left (in row r, less than c)
            auto left = row_set.lower_bound(c);
            if (left != row_set.begin()) {
                left--;
                int lr = r;
                int lc = *left;
                rows[lr].erase(lc);
                cols[lc].erase(lr);
            }

            // Right (in row r, greater than c)
            auto right = row_set.upper_bound(c);
            if (right != row_set.end()) {
                int rr = r;
                int rc = *right;
                rows[rr].erase(rc);
                cols[rc].erase(rr);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}