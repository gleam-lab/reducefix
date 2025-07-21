#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    unordered_map<int, unordered_set<int>> row_walls, col_walls;
    long long remaining_walls = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c) == 0) {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining_walls--;
        } else {
            // Check up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int pos = *it_up;
                if (row_walls[pos].count(c)) {
                    row_walls[pos].erase(c);
                    col_walls[c].erase(pos);
                    remaining_walls--;
                }
            }
            // Check down
            auto it_down = col_walls[c].upper_bound(r);
            if (it_down != col_walls[c].end()) {
                int pos = *it_down;
                if (row_walls[pos].count(c)) {
                    row_walls[pos].erase(c);
                    col_walls[c].erase(pos);
                    remaining_walls--;
                }
            }
            // Check left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int pos = *it_left;
                if (col_walls[pos].count(r)) {
                    col_walls[pos].erase(r);
                    row_walls[r].erase(pos);
                    remaining_walls--;
                }
            }
            // Check right
            auto it_right = row_walls[r].upper_bound(c);
            if (it_right != row_walls[r].end()) {
                int pos = *it_right;
                if (col_walls[pos].count(r)) {
                    col_walls[pos].erase(r);
                    row_walls[r].erase(pos);
                    remaining_walls--;
                }
            }
        }
    }
    
    cout << remaining_walls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}