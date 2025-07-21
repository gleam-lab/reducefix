#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);

    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's already a wall at the position (r, c)
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Find the nearest wall above and below the position (r, c)
            auto tate_iter_up = tate[c].upper_bound(r);
            if (tate_iter_up != tate[c].begin()) {
                --tate_iter_up;
                tate[c].erase(tate_iter_up);
                yoko[*tate_iter_up].erase(c);
            }

            // Find the nearest wall below the position (r, c)
            auto tate_iter_down = tate[c].lower_bound(r);
            if (tate_iter_down != tate[c].end()) {
                tate[c].erase(tate_iter_down);
                yoko[*tate_iter_down].erase(c);
            }

            // Find the nearest wall to the left of the position (r, c)
            auto yoko_iter_left = yoko[r].upper_bound(c);
            if (yoko_iter_left != yoko[r].begin()) {
                --yoko_iter_left;
                yoko[r].erase(yoko_iter_left);
                tate[*yoko_iter_left].erase(r);
            }

            // Find the nearest wall to the right of the position (r, c)
            auto yoko_iter_right = yoko[r].lower_bound(c);
            if (yoko_iter_right != yoko[r].end()) {
                yoko[r].erase(yoko_iter_right);
                tate[*yoko_iter_right].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}