#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    long long remaining = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                row_walls[*it_up].erase(c);
                col_walls[c].erase(it_up);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                row_walls[*it_down].erase(c);
                col_walls[c].erase(it_down);
                remaining--;
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                col_walls[*it_left].erase(r);
                row_walls[r].erase(it_left);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                col_walls[*it_right].erase(r);
                row_walls[r].erase(it_right);
                remaining--;
            }
        }
    }
    
    cout << remaining << '\n';
    return 0;
}