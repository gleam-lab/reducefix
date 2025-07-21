#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
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
            auto it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].begin()) {
                --it;
                int i = *it;
                row_walls[i].erase(C);
                col_walls[C].erase(i);
                remaining_walls--;
            }
            
            // Down
            it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].end()) {
                int i = *it;
                row_walls[i].erase(C);
                col_walls[C].erase(i);
                remaining_walls--;
            }
            
            // Left
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].begin()) {
                --it;
                int j = *it;
                row_walls[R].erase(j);
                col_walls[j].erase(R);
                remaining_walls--;
            }
            
            // Right
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].end()) {
                int j = *it;
                row_walls[R].erase(j);
                col_walls[j].erase(R);
                remaining_walls--;
            }
        }
    }
    
    cout << remaining_walls << "\n";
    
    return 0;
}