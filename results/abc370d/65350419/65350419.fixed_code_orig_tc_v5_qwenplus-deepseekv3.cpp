#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int ans = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Check up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                it_up--;
                int i = *it_up;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    ans--;
                }
            }
            
            // Check down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int i = *it_down;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    ans--;
                }
            }
            
            // Check left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int j = *it_left;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    ans--;
                }
            }
            
            // Check right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int j = *it_right;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    ans--;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}