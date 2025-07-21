#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(w), col(h);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // If there's a wall at (r,c), remove it
        if (col[r].count(c)) {
            col[r].erase(c);
            row[c].erase(r);
        } else {
            // Up
            auto& rc_set = row[c];
            auto it = rc_set.lower_bound(r);
            if (it != rc_set.begin()) {
                it--;
                int up_r = *it;
                col[up_r].erase(c);
                rc_set.erase(it);
            }

            // Down
            it = rc_set.lower_bound(r);
            if (it != rc_set.end()) {
                int down_r = *it;
                col[down_r].erase(c);
                rc_set.erase(it);
            }

            // Left
            auto& cr_set = col[r];
            auto jt = cr_set.lower_bound(c);
            if (jt != cr_set.begin()) {
                jt--;
                int left_c = *jt;
                row[left_c].erase(r);
                cr_set.erase(jt);
            }

            // Right
            jt = cr_set.lower_bound(c);
            if (jt != cr_set.end()) {
                int right_c = *jt;
                row[right_c].erase(r);
                cr_set.erase(jt);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    return 0;
}