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
    
    auto erase_wall = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            erase_wall(r, c);
            continue;
        }
        
        // Left
        auto it_left = row_walls[r].lower_bound(c);
        if (it_left != row_walls[r].begin()) {
            --it_left;
            erase_wall(r, *it_left);
        }
        
        // Right
        auto it_right = row_walls[r].lower_bound(c);
        if (it_right != row_walls[r].end()) {
            erase_wall(r, *it_right);
        }
        
        // Up
        auto it_up = col_walls[c].lower_bound(r);
        if (it_up != col_walls[c].begin()) {
            --it_up;
            erase_wall(*it_up, c);
        }
        
        // Down
        auto it_down = col_walls[c].lower_bound(r);
        if (it_down != col_walls[c].end()) {
            erase_wall(*it_down, c);
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << "\n";
    
    return 0;
}