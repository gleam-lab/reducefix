#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h + 2), cols(w + 2);
    for (int i = 1; i <= h; ++i) {
        rows[i].insert(0);
        rows[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        cols[j].insert(0);
        cols[j].insert(h + 1);
    }
    
    long long remaining = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (rows[r].count(c)) {
            // Already destroyed, do nothing
            continue;
        } else {
            // Destroy the current wall if present
            rows[r].insert(c);
            cols[c].insert(r);
            remaining--;
            
            // Find and destroy the nearest walls in four directions
            // Up
            auto it_up = cols[c].lower_bound(r);
            --it_up;
            if (*it_up > 0 && *it_up < r && !rows[*it_up].count(c)) {
                rows[*it_up].insert(c);
                cols[c].insert(*it_up);
                remaining--;
            }
            
            // Down
            auto it_down = cols[c].upper_bound(r);
            if (*it_down <= h && *it_down > r && !rows[*it_down].count(c)) {
                rows[*it_down].insert(c);
                cols[c].insert(*it_down);
                remaining--;
            }
            
            // Left
            auto it_left = rows[r].lower_bound(c);
            --it_left;
            if (*it_left > 0 && *it_left < c && !cols[*it_left].count(r)) {
                cols[*it_left].insert(r);
                rows[r].insert(*it_left);
                remaining--;
            }
            
            // Right
            auto it_right = rows[r].upper_bound(c);
            if (*it_right <= w && *it_right > c && !cols[*it_right].count(r)) {
                cols[*it_right].insert(r);
                rows[r].insert(*it_right);
                remaining--;
            }
        }
    }
    
    cout << remaining << '\n';
    
    return 0;
}