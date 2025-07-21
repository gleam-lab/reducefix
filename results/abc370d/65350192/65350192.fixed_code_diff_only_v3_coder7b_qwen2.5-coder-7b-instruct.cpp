#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);

    // Initialize the grid with walls
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    // Process each query
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at (r, c)
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Find the nearest wall above (r, c)
            auto tate_iter_up = tate[c].lower_bound(r);
            if (tate_iter_up != tate[c].begin()) {
                tate_iter_up--;
                int tmp = *tate_iter_up;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }

            // Find the nearest wall below (r, c)
            auto tate_iter_down = tate[c].upper_bound(r);
            if (tate_iter_down != tate[c].end()) {
                int tmp = *tate_iter_down;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }

            // Find the nearest wall to the left of (r, c)
            auto yoko_iter_left = yoko[r].lower_bound(c);
            if (yoko_iter_left != yoko[r].begin()) {
                yoko_iter_left--;
                int tmp = *yoko_iter_left;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }

            // Find the nearest wall to the right of (r, c)
            auto yoko_iter_right = yoko[r].upper_bound(c);
            if (yoko_iter_right != yoko[r].end()) {
                int tmp = *yoko_iter_right;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
        }
    }

    // Calculate the number of remaining walls
    int ans = 0;
    rep(i, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";

    return 0;
}