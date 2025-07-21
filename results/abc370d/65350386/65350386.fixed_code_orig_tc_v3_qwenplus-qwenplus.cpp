#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

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

        // Check if there's a wall at (r,c)
        if (col[r].count(c)) {
            // Destroy the wall at (r,c)
            col[r].erase(c);
            row[c].erase(r);
        } else {
            // Look up
            auto it_up = row[c].lower_bound(r);
            if (it_up != row[c].begin()) {
                --it_up;
                int u = *it_up;
                row[c].erase(it_up);
                col[u].erase(c);
            }

            // Look down
            auto it_down = row[c].lower_bound(r);
            if (it_down != row[c].end()) {
                int d = *it_down;
                row[c].erase(it_down);
                col[d].erase(c);
            }

            // Look left
            auto it_left = col[r].lower_bound(c);
            if (it_left != col[r].begin()) {
                --it_left;
                int l = *it_left;
                col[r].erase(it_left);
                row[l].erase(r);
            }

            // Look right
            auto it_right = col[r].lower_bound(c);
            if (it_right != col[r].end()) {
                int ri = *it_right;
                col[r].erase(it_right);
                row[ri].erase(r);
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