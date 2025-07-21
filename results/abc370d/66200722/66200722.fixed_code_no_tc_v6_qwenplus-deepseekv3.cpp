#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2), col_walls(W + 2);
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }
    
    long long remaining = (long long)H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (!row_walls[R].count(C)) {
            // Destroy the wall at (R, C)
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            remaining--;
        } else {
            // Look up
            auto it = col_walls[C].lower_bound(R);
            --it;
            if (*it > 0 && !row_walls[*it].count(C)) {
                row_walls[*it].insert(C);
                col_walls[C].insert(*it);
                remaining--;
            }
            
            // Look down
            it = col_walls[C].upper_bound(R);
            if (*it <= H && !row_walls[*it].count(C)) {
                row_walls[*it].insert(C);
                col_walls[C].insert(*it);
                remaining--;
            }
            
            // Look left
            it = row_walls[R].lower_bound(C);
            --it;
            if (*it > 0 && !col_walls[*it].count(R)) {
                col_walls[*it].insert(R);
                row_walls[R].insert(*it);
                remaining--;
            }
            
            // Look right
            it = row_walls[R].upper_bound(C);
            if (*it <= W && !col_walls[*it].count(R)) {
                col_walls[*it].insert(R);
                row_walls[R].insert(*it);
                remaining--;
            }
        }
    }
    
    cout << remaining << '\n';
    return 0;
}