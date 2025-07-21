#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row and column, keep a set of remaining wall positions
    vector<set<int>> row(w), col(h);
    
    // Initialize all cells with walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (col[r].count(c)) {
            // There's a wall at the position, remove it
            col[r].erase(c);
            row[c].erase(r);
        } else {
            // Look in four directions and destroy first walls found

            // Up
            auto& rc_set = row[c];
            auto it = rc_set.lower_bound(r);
            if (it != rc_set.begin()) {
                --it;
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
                --jt;
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

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << '\n';

    return 0;
}