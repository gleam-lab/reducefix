#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Initialize the sets with all row indices for each column and vice versa
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (tate[c].count(r)) {
            // Cell has a wall, destroy it
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Destroy first wall above
            auto up = tate[c].lower_bound(r);
            if (up != tate[c].begin()) {
                --up;
                int u_row = *up;
                tate[c].erase(u_row);
                yoko[u_row].erase(c);
            }

            // Destroy first wall below
            auto down = tate[c].lower_bound(r);
            if (down != tate[c].end()) {
                int d_row = *down;
                tate[c].erase(d_row);
                yoko[d_row].erase(c);
            }

            // Destroy first wall left
            auto left = yoko[r].lower_bound(c);
            if (left != yoko[r].begin()) {
                --left;
                int l_col = *left;
                yoko[r].erase(l_col);
                tate[l_col].erase(r);
            }

            // Destroy first wall right
            auto right = yoko[r].lower_bound(c);
            if (right != yoko[r].end()) {
                int r_col = *right;
                yoko[r].erase(r_col);
                tate[r_col].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += tate[i].size();
    }
    cout << ans << endl;
    return 0;
}