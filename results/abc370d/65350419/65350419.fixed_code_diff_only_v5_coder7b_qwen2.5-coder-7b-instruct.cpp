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
        r--; c--; // Convert to zero-based index
        
        if (!tate[c].empty() && *tate[c].begin() <= r && *prev(tate[c].end()) >= r) {
            // Wall already exists at (r, c)
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Find and remove the nearest wall above/below
            auto it_up = tate[c].upper_bound(r);
            if (it_up != tate[c].begin()) {
                it_up--;
                int tmp = *it_up;
                if (tmp < 0 || tmp >= h) continue; // Skip invalid indices
                tate[c].erase(it_up);
                yoko[tmp].erase(c);
            }
            
            // Find and remove the nearest wall below/above
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int tmp = *it_down;
                if (tmp < 0 || tmp >= h) continue; // Skip invalid indices
                tate[c].erase(it_down);
                yoko[tmp].erase(c);
            }
            
            // Find and remove the nearest wall left/right
            auto it_left = yoko[r].upper_bound(c);
            if (it_left != yoko[r].begin()) {
                it_left--;
                int tmp = *it_left;
                if (tmp < 0 || tmp >= w) continue; // Skip invalid indices
                yoko[r].erase(it_left);
                tate[tmp].erase(r);
            }
            
            // Find and remove the nearest wall right/left
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int tmp = *it_right;
                if (tmp < 0 || tmp >= w) continue; // Skip invalid indices
                yoko[r].erase(it_right);
                tate[tmp].erase(r);
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