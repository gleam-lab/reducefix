#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    long long remaining = (long long)H * W;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int up_r = *it_up;
                row_walls[up_r].erase(c);
                col_walls[c].erase(up_r);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int down_r = *it_down;
                row_walls[down_r].erase(c);
                col_walls[c].erase(down_r);
                remaining--;
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int left_c = *it_left;
                row_walls[r].erase(left_c);
                col_walls[left_c].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int right_c = *it_right;
                row_walls[r].erase(right_c);
                col_walls[right_c].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    
    return 0;
}