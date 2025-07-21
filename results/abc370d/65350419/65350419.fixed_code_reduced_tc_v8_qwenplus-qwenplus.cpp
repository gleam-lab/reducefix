#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row(w), col(h);
    
    // Initialize each column with all row indices
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            row[j].insert(i);
        }
    }
    
    // Initialize each row with all column indices
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            col[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Try to remove wall at (r,c)
        if (row[c].count(r)) {
            // Directly destroy the wall
            row[c].erase(r);
            col[r].erase(c);
        } else {
            // Up
            auto it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                it--;
                int up_r = *it;
                row[c].erase(up_r);
                col[up_r].erase(c);
            }

            // Down
            it = row[c].lower_bound(r);
            if (it != row[c].end()) {
                int down_r = *it;
                row[c].erase(down_r);
                col[down_r].erase(c);
            }

            // Left
            auto jt = col[r].lower_bound(c);
            if (jt != col[r].begin()) {
                jt--;
                int left_c = *jt;
                col[r].erase(left_c);
                row[left_c].erase(r);
            }

            // Right
            jt = col[r].lower_bound(c);
            if (jt != col[r].end()) {
                int right_c = *jt;
                col[r].erase(right_c);
                row[right_c].erase(r);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < w; ++j) {
        ans += row[j].size();
    }

    cout << ans << endl;
    return 0;
}