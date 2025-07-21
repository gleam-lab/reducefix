#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(w), col(h);

    // Initialize all walls present
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

        auto it = col[r].find(c);
        if (it != col[r].end()) {  // Wall exists at (r,c)
            col[r].erase(it);
            row[c].erase(r);
        } else {
            // Up
            auto up = row[c].lower_bound(r);
            if (up != row[c].begin()) {
                up--;
                int u = *up;
                row[c].erase(u);
                col[u].erase(c);
            }

            // Down
            auto down = row[c].lower_bound(r);
            if (down != row[c].end()) {
                int d = *down;
                row[c].erase(d);
                col[d].erase(c);
            }

            // Left
            auto left = col[r].lower_bound(c);
            if (left != col[r].begin()) {
                left--;
                int l = *left;
                col[r].erase(l);
                row[l].erase(r);
            }

            // Right
            auto right = col[r].lower_bound(c);
            if (right != col[r].end()) {
                int ri = *right;
                col[r].erase(ri);
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