#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h), cols(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    int remaining = h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (rows[r].count(c)) {
            // Direct hit - destroy this wall
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        } else {
            // Find first walls in four directions
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
    
    cout << remaining << '\n';
    return 0;
}