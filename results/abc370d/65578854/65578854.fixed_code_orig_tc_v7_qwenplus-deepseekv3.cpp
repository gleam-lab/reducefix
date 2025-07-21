#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H), col_walls(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    ll total = (ll)H * W;
    ll destroyed = 0;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        
        // Check if current cell has a wall
        if (row_walls[R].count(C)) {
            destroyed++;
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            continue;
        }
        
        // Find nearest walls in all four directions
        // Up
        auto it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].begin()) {
            --it;
            destroyed++;
            row_walls[*it].erase(C);
            col_walls[C].erase(it);
        }
        
        // Down
        it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].end()) {
            destroyed++;
            row_walls[*it].erase(C);
            col_walls[C].erase(it);
        }
        
        // Left
        it = row_walls[R].lower_bound(C);
        if (it != row_walls[R].begin()) {
            --it;
            destroyed++;
            row_walls[R].erase(it);
            col_walls[*it].erase(R);
        }
        
        // Right
        it = row_walls[R].lower_bound(C);
        if (it != row_walls[R].end()) {
            destroyed++;
            row_walls[R].erase(it);
            col_walls[*it].erase(R);
        }
    }
    
    cout << total - destroyed << '\n';
    return 0;
}