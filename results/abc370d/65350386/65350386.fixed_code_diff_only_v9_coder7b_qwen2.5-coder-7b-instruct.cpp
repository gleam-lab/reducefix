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
        
        // Check if there is a wall at position (r, c)
        if (tate[c].find(r) != tate[c].end()) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Find the nearest wall above and below
            auto tate_upper = tate[c].upper_bound(r);
            if (tate_upper != tate[c].begin()) {
                int upper = *prev(tate_upper);
                tate[c].erase(upper);
                yoko[upper].erase(c);
            }
            
            auto tate_lower = tate[c].lower_bound(r);
            if (tate_lower != tate[c].end()) {
                int lower = *tate_lower;
                tate[c].erase(lower);
                yoko[lower].erase(c);
            }
            
            // Find the nearest wall to the left and right
            auto yoko_left = yoko[r].lower_bound(c);
            if (yoko_left != yoko[r].begin()) {
                int left = *prev(yoko_left);
                yoko[r].erase(left);
                tate[left].erase(r);
            }
            
            auto yoko_right = yoko[r].upper_bound(c);
            if (yoko_right != yoko[r].end()) {
                int right = *yoko_right;
                yoko[r].erase(right);
                tate[right].erase(r);
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