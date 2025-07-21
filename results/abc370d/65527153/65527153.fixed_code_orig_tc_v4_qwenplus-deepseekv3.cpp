#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            continue;
        }
        
        // Check up
        auto it_up = col_walls[C].lower_bound(R);
        if (it_up != col_walls[C].begin()) {
            --it_up;
            int r = *it_up;
            row_walls[r].erase(C);
            col_walls[C].erase(r);
        }
        
        // Check down
        auto it_down = col_walls[C].upper_bound(R);
        if (it_down != col_walls[C].end()) {
            int r = *it_down;
            row_walls[r].erase(C);
            col_walls[C].erase(r);
        }
        
        // Check left
        auto it_left = row_walls[R].lower_bound(C);
        if (it_left != row_walls[R].begin()) {
            --it_left;
            int c = *it_left;
            row_walls[R].erase(c);
            col_walls[c].erase(R);
        }
        
        // Check right
        auto it_right = row_walls[R].upper_bound(C);
        if (it_right != row_walls[R].end()) {
            int c = *it_right;
            row_walls[R].erase(c);
            col_walls[c].erase(R);
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row_walls[i].size();
    }
    
    cout << ans << "\n";
    
    return 0;
}