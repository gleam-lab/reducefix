#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rows(H + 2);
    vector<set<int>> cols(W + 2);
    
    // Initialize all walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    int remaining = H * W;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        // Check if wall exists at (r,c)
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
            continue;
        }
        
        // Find nearest walls in four directions
        // Up
        auto it_up = cols[c].lower_bound(r);
        if (it_up != cols[c].begin()) {
            --it_up;
            rows[*it_up].erase(c);
            cols[c].erase(it_up);
            remaining--;
        }
        
        // Down
        auto it_down = cols[c].upper_bound(r);
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
        auto it_right = rows[r].upper_bound(c);
        if (it_right != rows[r].end()) {
            cols[*it_right].erase(r);
            rows[r].erase(it_right);
            remaining--;
        }
    }
    
    cout << remaining << '\n';
    return 0;
}