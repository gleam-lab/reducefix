#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> cols(w), rows(h);
    rep(i, h) rep(j, w) {
        cols[j].insert(i);
        rows[i].insert(j);
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (cols[c].count(r)) {
            cols[c].erase(r);
            rows[r].erase(c);
        } else {
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                it_up--;
                int i = *it_up;
                cols[c].erase(i);
                rows[i].erase(c);
            }
            
            // Down
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                int i = *it_down;
                cols[c].erase(i);
                rows[i].erase(c);
            }
            
            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                it_left--;
                int j = *it_left;
                rows[r].erase(j);
                cols[j].erase(r);
            }
            
            // Right
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                int j = *it_right;
                rows[r].erase(j);
                cols[j].erase(r);
            }
        }
    }
    
    int ans = 0;
    for (const auto& col : cols) {
        ans += col.size();
    }
    cout << ans << '\n';
    
    return 0;
}