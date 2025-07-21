#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    int remaining_walls = H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining_walls--;
        } else {
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int r = *it_up;
                if (row_walls[r].count(C)) {
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                    remaining_walls--;
                }
            }
            
            // Down
            auto it_down = col_walls[C].lower_bound(R);
            if (it_down != col_walls[C].end()) {
                int r = *it_down;
                if (row_walls[r].count(C)) {
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                    remaining_walls--;
                }
            }
            
            // Left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int c = *it_left;
                if (col_walls[c].count(R)) {
                    col_walls[c].erase(R);
                    row_walls[R].erase(c);
                    remaining_walls--;
                }
            }
            
            // Right
            auto it_right = row_walls[R].lower_bound(C);
            if (it_right != row_walls[R].end()) {
                int c = *it_right;
                if (col_walls[c].count(R)) {
                    col_walls[c].erase(R);
                    row_walls[R].erase(c);
                    remaining_walls--;
                }
            }
        }
    }
    
    cout << remaining_walls << "\n";
    
    return 0;
}