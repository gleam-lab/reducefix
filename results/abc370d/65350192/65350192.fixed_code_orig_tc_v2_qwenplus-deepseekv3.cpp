#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    
    // Initialize all walls as present
    rep(i, h) rep(j, w) {
        rows[i].insert(j);
        cols[j].insert(i);
    }
    
    ll remaining = (ll)h * w; // Track remaining walls
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (rows[r].count(c)) {
            // Wall exists at (r,c) - destroy it
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        } else {
            // No wall at (r,c) - destroy first walls in all four directions
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                --it_up;
                int i = *it_up;
                rows[i].erase(c);
                cols[c].erase(i);
                remaining--;
            }
            
            // Down
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                int i = *it_down;
                rows[i].erase(c);
                cols[c].erase(i);
                remaining--;
            }
            
            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                --it_left;
                int j = *it_left;
                rows[r].erase(j);
                cols[j].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                int j = *it_right;
                rows[r].erase(j);
                cols[j].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}