#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h+1), cols(w+1);
    
    // Initialize all walls (1-based indexing)
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    ll remaining = (ll)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        if (rows[r].count(c)) {
            // Wall exists at (r,c) - destroy it
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        } else {
            // Destroy first walls in four directions
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                --it_up;
                rows[*it_up].erase(c);
                cols[c].erase(it_up);
                remaining--;
            }
            
            // Down
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                rows[*it_down].erase(c);
                cols[c].erase(it_down);
                remaining--;
            }
            
            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                --it_left;
                cols[*it_left].erase(r);
                rows[r].erase(it_left);
                remaining--;
            }
            
            // Right
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                cols[*it_right].erase(r);
                rows[r].erase(it_right);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}