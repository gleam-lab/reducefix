#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Initialize sets with all positions
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
        
        // Check if there's a wall at the position
        if (tate[c].count(r)) {
            // Destroy wall at (r, c)
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Up direction
            auto up = tate[c].lower_bound(r);
            if (up != tate[c].begin()) {
                up--;
                int u = *up;
                tate[c].erase(u);
                yoko[u].erase(c);
            }

            // Down direction
            auto down = tate[c].lower_bound(r);
            if (down != tate[c].end()) {
                int d = *down;
                tate[c].erase(d);
                yoko[d].erase(c);
            }

            // Left direction
            auto left = yoko[r].lower_bound(c);
            if (left != yoko[r].begin()) {
                left--;
                int l = *left;
                yoko[r].erase(l);
                tate[l].erase(r);
            }

            // Right direction
            auto right = yoko[r].lower_bound(c);
            if (right != yoko[r].end()) {
                int ri = *right;
                yoko[r].erase(ri);
                tate[ri].erase(r);
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