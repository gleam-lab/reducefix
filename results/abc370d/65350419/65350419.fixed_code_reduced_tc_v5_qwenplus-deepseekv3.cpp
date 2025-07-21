#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    
    int remaining = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row[r].count(c)) {
            // Wall exists at (r,c)
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        } else {
            // No wall at (r,c) - destroy first walls in each direction
            // Up direction
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                it_up--;
                int i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
                remaining--;
            }
            
            // Down direction
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                int i = *it_down;
                row[i].erase(c);
                col[c].erase(i);
                remaining--;
            }
            
            // Left direction
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                it_left--;
                int j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
                remaining--;
            }
            
            // Right direction
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                int j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}