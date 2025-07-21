#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(h), col(w);
    rep(i,h) rep(j,w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    
    int ans = h * w;
    
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
        } else {
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                it_up--;
                row[*it_up].erase(c);
                col[c].erase(it_up);
                ans--;
            }
            
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                row[*it_down].erase(c);
                col[c].erase(it_down);
                ans--;
            }
            
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                it_left--;
                col[*it_left].erase(r);
                row[r].erase(it_left);
                ans--;
            }
            
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                col[*it_right].erase(r);
                row[r].erase(it_right);
                ans--;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}